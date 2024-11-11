// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "Enemy_Base.h"
#include "Enemy_Boss_Character.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API AEnemy_Boss_Character : public APlayerCharacter
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	float AttackRadius = 100;

	UPROPERTY(EditAnywhere)
	float DefenceRadius = 200;

	UFUNCTION(BlueprintNativeEvent)
	void ChangeStage(int StageNum);

	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons")
	TArray<TSubclassOf<ASpell_Base>> KnownSpellClasses_Stage2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons")
	TArray<TSubclassOf<ASpell_Base>> KnownSpellClasses_Stage3;
	*/
};
