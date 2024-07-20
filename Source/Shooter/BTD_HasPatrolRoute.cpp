// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_HasPatrolRoute.h"
#include "AIController.h"
#include "Enemy_Base.h"

UBTD_HasPatrolRoute::UBTD_HasPatrolRoute()
{
	NodeName = "Has patrol route";
}

bool UBTD_HasPatrolRoute::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (AEnemy_Base* OwnerEnemy = Cast<AEnemy_Base>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		if (OwnerEnemy->GetPatrolRoute())
		{
			return true;
		}
	}
	return false;
}
