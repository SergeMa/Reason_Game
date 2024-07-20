// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IInteractable.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Weapon_Pickup.generated.h"

class AWeapon_Base;

UCLASS()
class SHOOTER_API AWeapon_Pickup : public AActor, public IIInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon_Pickup();

	UFUNCTION(BlueprintCallable)
	virtual void Interact() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AWeapon_Base> Weapon_Class;

private:
	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxCollider;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponMesh;


};
