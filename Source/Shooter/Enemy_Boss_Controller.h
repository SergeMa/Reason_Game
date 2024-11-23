// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy_Base_Controller.h"
#include "Enemy_Boss_Controller.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API AEnemy_Boss_Controller : public AEnemy_Base_Controller
{
	GENERATED_BODY()

protected:
	virtual void OnPossess(APawn* InPawn) override;

public:
	virtual void Tick(float DeltaSeconds) override;
};
