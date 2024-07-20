// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_Pickup.h"
#include "Kismet/GameplayStatics.h"
#include "Weapon_Base.h"

// Sets default values
AWeapon_Pickup::AWeapon_Pickup()
{
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(RootComponent);
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(BoxCollider);
}

void AWeapon_Pickup::Interact(){
	//UE_LOG(LogTemp, Error, TEXT("New weapon equipped"));
	Destroy();
}

