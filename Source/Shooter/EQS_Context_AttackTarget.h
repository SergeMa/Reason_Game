// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EQS_Context_AttackTarget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UEQS_Context_AttackTarget : public UEnvQueryContext
{
	GENERATED_BODY()
	
protected:
	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;
};
	