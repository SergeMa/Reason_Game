// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_IsWieldingWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UBTD_IsWieldingWeapon : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTD_IsWieldingWeapon();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};