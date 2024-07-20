// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Attack_Default.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UBTT_Attack_Default : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_Attack_Default();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
