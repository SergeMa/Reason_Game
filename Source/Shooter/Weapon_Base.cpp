// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_Base.h"
#include "Character_Base.h"
#include "Engine/DamageEvents.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AWeapon_Base::AWeapon_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	WeaponMesh->SetupAttachment(RootComponent);
}

USkeletalMeshComponent* AWeapon_Base::GetWeaponMesh() const
{
	return WeaponMesh;
}

EWeaponType AWeapon_Base::GetWeaponType() const
{
	return WeaponType;
}

void AWeapon_Base::DealDamage(ACharacter_Base* Victim)
{
	FDamageEvent DamageEvent;
	Victim->TakeDamage(Damage, DamageEvent, GetOwnerController(), this);
}

AController* AWeapon_Base::GetOwnerController()
{
	if (APawn* PawnOwner = Cast<APawn>(GetOwner()))	return PawnOwner->GetController();

	return nullptr;
}

void AWeapon_Base::ClearHitActors()
{
	HitActors.Empty();
}

void AWeapon_Base::DropWeapon()
{
	UE_LOG(LogTemp, Error, TEXT("~~~~No drop weapon function declared~~~~"));
}

void AWeapon_Base::HandleCollision()
{
	UE_LOG(LogTemp, Error, TEXT("~~~~No handle collision function created~~~~"));
}

