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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	EWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

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

	UPROPERTY(EditDefaultsOnly)
	FName SocketEquipName;

	UPROPERTY(EditDefaultsOnly)
	FName SocketDisarmName;

	AController* GetOwnerController();
};
