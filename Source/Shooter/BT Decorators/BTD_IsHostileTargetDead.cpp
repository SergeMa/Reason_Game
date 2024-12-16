// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsHostileTargetDead.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../Character_Base.h"

UBTD_IsHostileTargetDead::UBTD_IsHostileTargetDead()
{
	NodeName = "Is hostile target dead";
}

bool UBTD_IsHostileTargetDead::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	ACharacter_Base* HostileTargetActor = Cast<ACharacter_Base>(BlackboardComp->GetValueAsObject(HostileTarget.SelectedKeyName));

	if (HostileTargetActor->IsDead())
	{
		return true;
	}
	return false;
}
