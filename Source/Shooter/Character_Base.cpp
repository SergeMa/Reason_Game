// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Base.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Weapon_Base.h"
#include "Weapon_Melee.h"
#include "Weapon_Pickup.h"
#include "MovementHelper.h"
#include "Components/CapsuleComponent.h"


// Sets default values
ACharacter_Base::ACharacter_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACharacter_Base::BeginPlay()
{
	Super::BeginPlay();

	MovementHelper::InitializeMovementSpeedMap();

	if (Weapon_Class)
	{
		Weapon = GetWorld()->SpawnActor<AWeapon_Base>(Weapon_Class);
		Weapon->SetOwner(this);
		Weapon_Disarm_Attach();
	}

	SetMoveSpeed(LastMoveSpeed);
	Health = MaxHealth;
}

void ACharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Called every frame
void ACharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Weapon && CastChecked<AWeapon_Melee>(Weapon) && bIsAttacking)
	{
		Weapon->HandleCollision();
	}
}

float ACharacter_Base::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageApplied = FMath::Min(Health, DamageApplied);
	Health -= DamageApplied;
	UE_LOG(LogTemp, Warning, TEXT("Current health = %f"), Health);

	if (IsDead())
	{
		DropWeapon();

		GetCharacterMovement()->DisableMovement();
		GetCharacterMovement()->StopMovementImmediately();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
		GetMesh()->SetSimulatePhysics(true);
		GetMesh()->WakeAllRigidBodies();

		DetachFromControllerPendingDestroy();
	}
	return DamageApplied;
}

void ACharacter_Base::Weapon_Equip()
{
	if (Weapon == nullptr || GetCharacterMovement()->IsFalling() || Weapon->GetWeaponType() == EWeaponType::WT_None) return;

	if (WeaponTypeEquipped == Weapon->GetWeaponType())
	{
		WeaponTypeEquipped = EWeaponType::WT_None;
	}
	else
	{
		WeaponTypeEquipped = Weapon->GetWeaponType();
	}

	NullifyWalkSpeed();
}

void ACharacter_Base::Weapon_Attack()
{
	if (WeaponTypeEquipped == EWeaponType::WT_None || bIsAttacking == true || GetCharacterMovement()->IsFalling()) return;

	bIsAttacking = true;
	NullifyWalkSpeed();
}

void ACharacter_Base::Interact()
{
	//Implementation moved to PlayerCharacter.cpp
}

void ACharacter_Base::DropWeapon()
{

	if (!IsDead() && (!Weapon || bIsAttacking || GetCharacterMovement()->MaxWalkSpeed == 0))	return;

	if (WeaponTypeEquipped != EWeaponType::WT_None)
	{
		WeaponTypeEquipped = EWeaponType::WT_None;
	}
	Weapon->DropWeapon();
	Weapon = nullptr;
}

void ACharacter_Base::SetMoveSpeed(ECharacterMovementSpeed MoveSpeedToSet)
{
	LastMoveSpeed = MoveSpeedToSet;
	ReturnMoveSpeed();
}

AWeapon_Base* ACharacter_Base::GetWeaponObject()
{
	if (Weapon == nullptr) return nullptr;

	return Weapon;
}

bool ACharacter_Base::IsWeaponEquipped()
{
	if (Weapon) return true;

	return false;
}

EWeaponType ACharacter_Base::GetWeaponType()
{
	if (Weapon == nullptr) return EWeaponType::WT_None;

	return WeaponTypeEquipped;
}

USkeletalMeshComponent* ACharacter_Base::GetWeaponMeleeMesh()
{
	if (!Weapon) return nullptr;

	return Weapon->GetWeaponMesh();
}

void ACharacter_Base::Weapon_Disarm_Attach()
{
	if (Weapon == nullptr)	return;

	ReturnMoveSpeed();
	Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, Weapon->SocketDisarmName);
}

void ACharacter_Base::Weapon_Equip_Attach()
{
	if (Weapon == nullptr)	return;

	ReturnMoveSpeed();
	Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, Weapon->SocketEquipName);
}

void ACharacter_Base::NullifyWalkSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed = MovementHelper::GetMovementSpeed(ECharacterMovementSpeed::Frozen);
}

void ACharacter_Base::ReturnMoveSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed = MovementHelper::GetMovementSpeed(LastMoveSpeed);
}

bool ACharacter_Base::IsDead()
{
	return Health <= 0;
}



