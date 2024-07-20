// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character_Base.h"
#include "IEnemyAI.h"
#include "Enemy_Base.generated.h"

/**
 * 
 */
class AAI_PatrolRoute;

UCLASS()
class SHOOTER_API AEnemy_Base : public ACharacter_Base, public IIEnemyAI
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AAI_PatrolRoute* GetPatrolRoute() override;

	UPROPERTY(EditAnywhere)
	float AttackRadius = 200;

	UPROPERTY(EditAnywhere)
	float DefenceRadius = 400;

private:
	UPROPERTY(EditInstanceOnly)
	AAI_PatrolRoute* PatrolRoute;
};
