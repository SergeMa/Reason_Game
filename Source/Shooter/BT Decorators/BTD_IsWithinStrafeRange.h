// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_IsWithinStrafeRange.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UBTD_IsWithinStrafeRange : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UBTD_IsWithinStrafeRange();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	float ErrorMargin = 50;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector IdealRange;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector AttackTarget;

};
