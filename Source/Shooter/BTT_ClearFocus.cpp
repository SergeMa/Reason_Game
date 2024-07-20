// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_ClearFocus.h"
#include "AIController.h"

UBTT_ClearFocus::UBTT_ClearFocus()
{
	NodeName = "Clear Focus";
}

EBTNodeResult::Type UBTT_ClearFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (AAIController* OwnerCont = Cast<AAIController>(OwnerComp.GetAIOwner()))
	{
		OwnerCont->ClearFocus(EAIFocusPriority::Gameplay);
		
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
