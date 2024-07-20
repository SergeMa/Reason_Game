// Fill out your copyright notice in the Description page of Project Settings.


#include "EQS_Context_AttackTarget.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Enemy_Base_Controller.h"
#include "AIController.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"

void UEQS_Context_AttackTarget::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	AActor* QuerierActor = Cast<AActor>(QueryInstance.Owner.Get());
	if (AEnemy_Base_Controller* EnemyCast = Cast<AEnemy_Base_Controller>(QuerierActor->GetInstigatorController()))
	{
		UEnvQueryItemType_Actor::SetContextHelper(ContextData, EnemyCast->GetAttackTarget());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EQS broken"));
	}
}
