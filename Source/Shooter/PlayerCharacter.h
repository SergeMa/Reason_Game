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
class ASpell_Base;
class UPlayerWidget;
class UWidgetComponent;

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
	virtual void Tick(float DeltaTime) override;

	void Weapon_Equip() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons")
	TArray<TSubclassOf<ASpell_Base>> KnownSpellClasses;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapons")
	TArray<AWeapon_Base*> WeaponList;

	virtual void Die() override;

protected:
	void DropWeapon() override;

	virtual void SetMoveSpeed(ECharacterMovementSpeed MoveSpeedToSet);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Aditional components")
	class USphereComponent* CameraHolder;

	UPROPERTY(EditDefaultsOnly, Category = "Aditional components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, Category = "Aditional components")
	float SpringArmExtendedLength = 350.f;

	UPROPERTY(EditDefaultsOnly, Category = "Aditional components")
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
	UInputAction* Weapon_AttackAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* ChangeWalkSpeedAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* InteractAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* DropAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* ChangeCameraLengthAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* EquipWeaponAction;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPlayerWidget> PlayerWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UPlayerWidget> PlayerWidget;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void JumpFunction(const FInputActionValue& Value);

	UFUNCTION()
	AActor* CheckForInteractable();

	UFUNCTION()
	void SwitchToWalk();

	UFUNCTION()
	void SwitchToRun();

	UFUNCTION(BlueprintCallable)
	void ChangeCameraLength();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION()
	void EquipWeaponWithIndex(const FInputActionValue& Value);

	void Interact() override;

	UFUNCTION(BlueprintCallable)
	void CastSpell();
};
