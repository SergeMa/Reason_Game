// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/SphereComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Weapon_Base.h"
#include "Weapon_Pickup.h"
#include "IInteractable.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraHolder = CreateDefaultSubobject<USphereComponent>("CameraHolder");
	CameraHolder->SetupAttachment(GetMesh());

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->TargetArmLength = 0;
	SpringArm->SetupAttachment(CameraHolder);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MovementInputMappingContext, 0);
		}
	}
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &APlayerCharacter::JumpFunction);
		EnhancedInputComponent->BindAction(Weapon_Melee_EquipAction, ETriggerEvent::Started, this, &APlayerCharacter::Weapon_Equip);
		EnhancedInputComponent->BindAction(ChangeWalkSpeedAction, ETriggerEvent::Started, this, &APlayerCharacter::SwitchToRun);
		EnhancedInputComponent->BindAction(ChangeWalkSpeedAction, ETriggerEvent::Completed, this, &APlayerCharacter::SwitchToWalk);
		EnhancedInputComponent->BindAction(Weapon_AttackAction, ETriggerEvent::Triggered, this, &Super::Weapon_Attack);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &APlayerCharacter::Interact);
		EnhancedInputComponent->BindAction(DropAction, ETriggerEvent::Started, this, &APlayerCharacter::DropWeapon);
	}
}

void APlayerCharacter::Weapon_Equip()
{
	
	if (Weapon == nullptr || GetCharacterMovement()->IsFalling() || Weapon->GetWeaponType() == EWeaponType::WT_None) return;
	
	if (WeaponTypeEquipped == Weapon->GetWeaponType()) //Weapon is being Disarmed
	{
		SpringArm->AddRelativeLocation(FVector(0, -20, 0));
	}
	else //Weapon is being Equipped
	{
		SpringArm->AddRelativeLocation(FVector(0, 20, 0));
	}
	
	Super::Weapon_Equip();
}

void APlayerCharacter::DropWeapon()
{
	if (!IsDead() && (!Weapon || bIsAttacking || GetCharacterMovement()->MaxWalkSpeed == 0))	return;
	
	if (WeaponTypeEquipped != EWeaponType::WT_None)
	{
		SpringArm->AddRelativeLocation(FVector(0, -20, 0));
	}
	
	Super::DropWeapon();
}

void APlayerCharacter::SetMoveSpeed(ECharacterMovementSpeed MoveSpeedToSet)
{
	if (GetCharacterMovement()->MaxWalkSpeed == 0) return;

	Super::SetMoveSpeed(MoveSpeedToSet);
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MoveVector = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector() * MoveVector.X);
	AddMovementInput(GetActorRightVector() * MoveVector.Y);
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookVector = Value.Get<FVector2D>();
	FRotator CurrentRotation = CameraHolder->GetComponentRotation() + FRotator(LookVector.Y, 0, 0);
	float ClampedPitch = FMath::Clamp(CurrentRotation.Pitch, -60.f, 60.0f);
	FRotator NewRotation = FRotator(ClampedPitch, CurrentRotation.Yaw, CurrentRotation.Roll);
	CameraHolder->SetWorldRotation(NewRotation);
	AddControllerYawInput(LookVector.X);
}

void APlayerCharacter::JumpFunction(const FInputActionValue& Value)
{
	if (GetCharacterMovement()->IsFalling())	return;
	
	Jump();
}

AActor* APlayerCharacter::CheckForInteractable()
{
	FVector Start = Camera->GetComponentLocation();
	FVector End = Start + (Camera->GetForwardVector() * 1000.0f);  // Adjust the distance as needed
	FHitResult HitResult;

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams);

	if (bHit)
	{
		AActor* HitActor = HitResult.GetActor();
		if (HitActor && HitActor->GetClass()->ImplementsInterface(UIInteractable::StaticClass()))
		{
			return HitActor;
		}
	}
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 0.2f);

	return nullptr;
}

void APlayerCharacter::SwitchToWalk()
{
	SetMoveSpeed(ECharacterMovementSpeed::Walk);
}

void APlayerCharacter::SwitchToRun()
{
	SetMoveSpeed(ECharacterMovementSpeed::Run);
}

void APlayerCharacter::Interact()
{
	if (IIInteractable* Interactable = Cast<IIInteractable>(CheckForInteractable()))
	{
		if (AWeapon_Pickup* WP_Interactable = Cast<AWeapon_Pickup>(Interactable))
		{
			if (WP_Interactable->Weapon_Class == nullptr) {
				UE_LOG(LogTemp, Error, TEXT("Weapon pickup class not specified"));
				return;
			}

			DropWeapon();
			Weapon = GetWorld()->SpawnActor<AWeapon_Base>(WP_Interactable->Weapon_Class);
			Weapon->SetOwner(this);
			Super::Weapon_Disarm_Attach();
		}
		Interactable->Interact();
	};
}