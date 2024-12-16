// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_SetFocus.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_SetFocus::UBTT_SetFocus()
{
	NodeName = "Set focus";

}

EBTNodeResult::Type UBTT_SetFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (AAIController* OwnerCont = Cast<AAIController>(OwnerComp.GetAIOwner())) 
	{
		AActor* TargetActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey()));

		OwnerCont->SetFocus(TargetActor);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
