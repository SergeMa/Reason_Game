// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Projectile.h"
#include "Components\BoxComponent.h"
#include "Particles\ParticleSystemComponent.h"
#include "Engine\DamageEvents.h"
#include "Kismet\GameplayStatics.h"
#include "Character_Base.h"
#include "Spell_Base.h"
#include "Components\StaticMeshComponent.h"
#include "GameFramework\ProjectileMovementComponent.h"

// Sets default values
ASpell_Projectile::ASpell_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>("BoxCollider");
	RootComponent = BoxCollider;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	ProjectileMesh->SetupAttachment(BoxCollider);

	SpellVisuals = CreateDefaultSubobject<UParticleSystemComponent>("Visuals");
	SpellVisuals->SetupAttachment(BoxCollider);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile movement comp");
	ProjectileMovementComponent->UpdatedComponent = BoxCollider;
	ProjectileMovementComponent->InitialSpeed = 1000.f;
	ProjectileMovementComponent->MaxSpeed = 1000.f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = false;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void ASpell_Projectile::BeginPlay()
{
	Super::BeginPlay();
	BoxCollider->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
}

void ASpell_Projectile::OnCollisionEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!CasterCharacter || OtherActor == CasterCharacter) return;

	if (GEngine) 
	{
		FString Message = FString::Printf(TEXT("Collided with: %s, CasterChar: %s"), *OtherActor->GetName(), *CasterCharacter->GetName());
		GEngine->AddOnScreenDebugMessage(1, 30, FColor::Black, Message);
	}

	if (ACharacter_Base* HitChar = Cast<ACharacter_Base>(OtherActor)) {
		DealDamage(HitChar);
		SpellAfterEffect(HitChar);
	}

	if (SpellHitVisual) {
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SpellHitVisual, GetActorTransform());
	}

	Destroy();
}

void ASpell_Projectile::DealDamage(ACharacter_Base* Victim)
{
	if (!CasterCharacter) return;

	FDamageEvent DamageEvent;
	Victim->TakeDamage(Damage, DamageEvent, CasterCharacter->GetController(), this);
}

void ASpell_Projectile::InitializeProjectile(ACharacter_Base* CasterCharacterInput, float DamageInput)
{
	Damage = DamageInput;
	CasterCharacter = CasterCharacterInput;
	//SetActorRotation(CasterCharacter->GetActorForwardVector().Rotation());
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ASpell_Projectile::OnCollisionEnter);
}

void ASpell_Projectile::SpellAfterEffect_Implementation(ACharacter_Base* Victim)
{
	//Event declared in Blueprint
}

// Called every frame
void ASpell_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

