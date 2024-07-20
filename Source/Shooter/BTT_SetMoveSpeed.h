// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ECharacterMovementSpeed.h"
#include "BTT_SetMoveSpeed.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UBTT_SetMoveSpeed : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_SetMoveSpeed();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere)
	ECharacterMovementSpeed SpeedToSet;
};
