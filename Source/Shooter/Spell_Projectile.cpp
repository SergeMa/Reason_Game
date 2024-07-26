// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Projectile.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine/DamageEvents.h"
#include "Kismet/GameplayStatics.h"
#include "Character_Base.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ASpell_Projectile::ASpell_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>("BoxCollider");
	RootComponent = BoxCollider;
	SpellVisuals = CreateDefaultSubobject<UParticleSystemComponent>("Visuals");
	SpellVisuals->SetupAttachment(BoxCollider);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile movement comp");
	ProjectileMovementComponent->UpdatedComponent = BoxCollider;
	ProjectileMovementComponent->InitialSpeed = 1000.f;
	ProjectileMovementComponent->MaxSpeed = 1000.f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = false;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;

	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ASpell_Projectile::OnCollisionEnter);
}

// Called when the game starts or when spawned
void ASpell_Projectile::BeginPlay()
{
	Super::BeginPlay();
}

void ASpell_Projectile::OnCollisionEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ACharacter_Base* HitChar = Cast<ACharacter_Base>(OtherActor)) {
		DealDamage(HitChar);
	}
	if (SpellHitVisual) {
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SpellHitVisual, GetActorTransform());
	}

	Destroy();
}

void ASpell_Projectile::DealDamage(ACharacter_Base* Victim)
{
	if (!OwnerCharacter) return;

	FDamageEvent DamageEvent;

	Victim->TakeDamage(Damage, DamageEvent, OwnerCharacter->GetController(), this);
}

// Called every frame
void ASpell_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

