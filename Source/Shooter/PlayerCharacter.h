// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character_Base.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
class UInputAction;
class UInputMappingContext;

UCLASS()
class SHOOTER_API APlayerCharacter : public ACharacter_Base
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	void Weapon_Equip() override;


protected:
	void DropWeapon() override;

	virtual void SetMoveSpeed(ECharacterMovementSpeed MoveSpeedToSet);

private:
	UPROPERTY(EditAnywhere)
	class USphereComponent* CameraHolder;

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* MovementInputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* Weapon_Melee_EquipAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* Weapon_AttackAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* ChangeWalkSpeedAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* InteractAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* DropAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void JumpFunction(const FInputActionValue& Value);


	UFUNCTION()
	AActor* CheckForInteractable();

	UFUNCTION()
	void SwitchToWalk();

	UFUNCTION()
	void SwitchToRun();

	void Interact() override;
};
