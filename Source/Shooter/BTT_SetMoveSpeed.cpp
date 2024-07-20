// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_SetMoveSpeed.h"
#include "Character_Base.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTT_SetMoveSpeed::UBTT_SetMoveSpeed()
{
	NodeName = "Set move speed to";
}

EBTNodeResult::Type UBTT_SetMoveSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (ACharacter_Base* OwnerChar = Cast<ACharacter_Base>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		if (OwnerChar->GetCharacterMovement()->MaxWalkSpeed == 0)	return EBTNodeResult::Failed;

		OwnerChar->SetMoveSpeed(SpeedToSet);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
