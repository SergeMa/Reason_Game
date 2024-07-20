// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_SetStateToPassive.h"
#include "Enemy_Base_Controller.h"
#include "AIController.h"

UBTT_SetStateToPassive::UBTT_SetStateToPassive()
{
	NodeName = "Switch to passive state";
}

EBTNodeResult::Type UBTT_SetStateToPassive::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr) return EBTNodeResult::Failed;

	AEnemy_Base_Controller* OwnerChar = Cast<AEnemy_Base_Controller>(OwnerComp.GetAIOwner());
	if (OwnerChar)
	{
		OwnerChar->SetStateAsPassive();
		EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
