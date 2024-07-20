// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsWithinStrafeRange.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTD_IsWithinStrafeRange::UBTD_IsWithinStrafeRange()
{
	NodeName = "Is within strafe range";
}

bool UBTD_IsWithinStrafeRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	float IdealFloat = BlackboardComp->GetValueAsFloat(IdealRange.SelectedKeyName);
	if (AActor* AttackPawn = Cast<AActor>(BlackboardComp->GetValueAsObject(AttackTarget.SelectedKeyName)))
	{
		float DistanceBetweenPawns = AttackPawn->GetDistanceTo(OwnerComp.GetAIOwner()->GetPawn());
		return DistanceBetweenPawns - ErrorMargin <= IdealFloat;
	}
	return true;
}
