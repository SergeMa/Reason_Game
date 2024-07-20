// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponType.h"

#include "Weapon_Base.generated.h"

class USkeletalMeshComponent;
class ACharacter_Base;

UCLASS(Abstract)
class SHOOTER_API AWeapon_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon_Base();

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWeaponType WeaponType;

	TSet<AActor*> HitActors;

public:
	UFUNCTION(BlueprintPure)
	USkeletalMeshComponent* GetWeaponMesh() const;

	UFUNCTION(BlueprintPure)
	EWeaponType GetWeaponType() const;

	UFUNCTION(BlueprintCallable)
	virtual void DealDamage(ACharacter_Base* Victim);

	UFUNCTION(BlueprintCallable)
	void ClearHitActors();

	UFUNCTION(BlueprintCallable)
	virtual void DropWeapon();

	UFUNCTION()
	virtual void HandleCollision();

	UPROPERTY(EditAnywhere)
	FName SocketEquipName;

	UPROPERTY(EditAnywhere)
	FName SocketDisarmName;

	AController* GetOwnerController();
};
