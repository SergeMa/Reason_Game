// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_SetFocus.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UBTT_SetFocus : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_SetFocus();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};