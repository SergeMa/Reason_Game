// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon_Base.h"
#include "Weapon_Melee.generated.h"

/**
 * 
 */

UCLASS()
class SHOOTER_API AWeapon_Melee : public AWeapon_Base
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	float WeaponLength = 120;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AWeapon_Pickup> WeaponPickupClass;

public:
	void HandleCollision() override;

	void DropWeapon() override;
};
