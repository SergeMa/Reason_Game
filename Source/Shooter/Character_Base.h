// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "WeaponType.h"
#include "ECharacterMovementSpeed.h"
#include "Character_Base.generated.h"

class AWeapon_Base;
class AWeapon_Ranged;


UCLASS()
class SHOOTER_API ACharacter_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacter_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Weapons")
	TSubclassOf<AWeapon_Base> Weapon_Class;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapons")
	bool bIsAttacking = false;

	UFUNCTION(BlueprintCallable)
	bool IsDead();

	UFUNCTION()
	void Weapon_Attack();

	UFUNCTION()
	virtual void Weapon_Equip();

	UFUNCTION(BlueprintCallable)
	virtual void DropWeapon();

	UFUNCTION(BlueprintCallable)
	virtual void SetMoveSpeed(ECharacterMovementSpeed MoveSpeedToSet);

	UFUNCTION(BlueprintPure)
	EWeaponType GetWeaponType();

	UFUNCTION(BlueprintCallable)
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	UPROPERTY(EditAnywhere)
	float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
	float Health = 1;

	UPROPERTY(VisibleAnywhere, Category = "Weapons")
	AWeapon_Base* Weapon;

	UPROPERTY(VisibleAnywhere, Category = "Weapons")
	EWeaponType WeaponTypeEquipped = EWeaponType::WT_None;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	ECharacterMovementSpeed LastMoveSpeed = ECharacterMovementSpeed::Walk;

	UFUNCTION(BlueprintPure)
	AWeapon_Base* GetWeaponObject();

	UFUNCTION(BlueprintPure)
	bool IsWeaponEquipped();

	UFUNCTION(BlueprintPure)
	USkeletalMeshComponent* GetWeaponMeleeMesh();

	UFUNCTION(BlueprintCallable)
	void Weapon_Disarm_Attach();

	UFUNCTION(BlueprintCallable)
	void Weapon_Equip_Attach();

	UFUNCTION(BlueprintCallable)
	void NullifyWalkSpeed();

	UFUNCTION(BlueprintCallable)
	void ReturnMoveSpeed();

	UFUNCTION()
	virtual void Interact();
};
