// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_MoveToIdealRange.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UBTT_MoveToIdealRange : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_MoveToIdealRange();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector IdealRange;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector AttackTarget;
};
