// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "Enemy_Base.h"
#include "Enemy_Boss_Character.generated.h"

class UBossWidget;

UCLASS()
class SHOOTER_API AEnemy_Boss_Character : public APlayerCharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(EditAnywhere)
	float AttackMeleeRadius = 100;

	UPROPERTY(EditAnywhere)
	float DefenceMeleeRadius = 200;

	UPROPERTY(EditAnywhere)
	float AttackRangedRadius = 400;

	UPROPERTY(EditAnywhere)
	float DefenceRangedRadius = 500;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int CurrentStage = 0;

	UFUNCTION(BlueprintNativeEvent)
	void ChangeStage(int StageNum);

	UFUNCTION(BlueprintCallable)
	void HandleStageTransition();

	UFUNCTION(BlueprintCallable)
	void CreateBossWidget();

	UFUNCTION(BlueprintCallable)
	void DestroyBossWidget();

	virtual void Die() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UBossWidget> BossWidgetClass;

	UPROPERTY()
	TObjectPtr<UBossWidget> BossWidget;

	void EquipWeaponWithIndex(int WeaponIndex) override;

private:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
};
