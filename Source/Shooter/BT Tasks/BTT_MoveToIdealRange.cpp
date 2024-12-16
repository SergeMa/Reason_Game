// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_MoveToIdealRange.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTT_MoveToIdealRange::UBTT_MoveToIdealRange()
{
	NodeName = "Move to ideal range";
}

EBTNodeResult::Type UBTT_MoveToIdealRange::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	float IdealFloat = BlackboardComp->GetValueAsFloat(IdealRange.SelectedKeyName);
	AActor* AttackPawn = Cast<AActor>(BlackboardComp->GetValueAsObject(AttackTarget.SelectedKeyName));

	if (AAIController* AICont = OwnerComp.GetAIOwner())
	{
		AICont->MoveToActor(AttackPawn, IdealFloat);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
