// Fill out your copyright notice in the Description page of Project Settings
#include "BTT_Attack_Default.h"
#include "../Character_Base.h"
#include "AIController.h"

UBTT_Attack_Default::UBTT_Attack_Default()
{
	NodeName = "Simple Attack";
}

EBTNodeResult::Type UBTT_Attack_Default::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	bNotifyTick = 1;

	ACharacter_Base* OwnerChar = Cast<ACharacter_Base>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerChar && OwnerChar->bIsAttacking)	return EBTNodeResult::Failed;

	OwnerChar->Weapon_Attack();
	return EBTNodeResult::InProgress;
}

void UBTT_Attack_Default::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	ACharacter_Base* OwnerChar = Cast<ACharacter_Base>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerChar && OwnerChar->bIsAttacking == false)
	{
		FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
	}
}


