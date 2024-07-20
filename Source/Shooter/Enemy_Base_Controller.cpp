// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Base_Controller.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Character_Base.h"
#include "E_EnemyAIState.h"
#include "WeaponType.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Damage.h"
#include "Enemy_Base.h"

void AEnemy_Base_Controller::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (AIBehaviorTree)
	{
		RunBehaviorTree(AIBehaviorTree);
		BlackboardComp = GetBlackboardComponent();

		AEnemy_Base* EnemyPawn = Cast<AEnemy_Base>(GetPawn());

		BlackboardComp->SetValueAsFloat(TEXT("AttackRadius"), EnemyPawn->AttackRadius);
		BlackboardComp->SetValueAsFloat(TEXT("DefendRadius"), EnemyPawn->DefenceRadius);
	}

	if (GetPerceptionComponent())
	{
		PerceptionComp = GetAIPerceptionComponent();
		PerceptionComp->OnPerceptionUpdated.AddDynamic(this, &AEnemy_Base_Controller::OnPerceptionUpdated);
	}
	SetStateAsPassive();

}

void AEnemy_Base_Controller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

bool AEnemy_Base_Controller::isDead() const
{
	if (ACharacter_Base* ControlledCharacter = Cast<ACharacter_Base>(GetPawn())) return ControlledCharacter->IsDead();

	return true;
}

void AEnemy_Base_Controller::CanSenseActor(AActor* SensedActor, E_AISense Sense)
{
	if (!PerceptionComp)	return;

	FActorPerceptionBlueprintInfo PerceptionInfo;
	PerceptionComp->GetActorsPerception(SensedActor, PerceptionInfo);
	for (FAIStimulus const Stimulus : PerceptionInfo.LastSensedStimuli)
	{
		TSubclassOf<UAISense> SenseUsed = UAIPerceptionSystem::GetSenseClassForStimulus(GetWorld(), Stimulus);
		switch (Sense)
		{
		case E_AISense::Sight:
		{
			if (SenseUsed == UAISense_Sight::StaticClass())
			{
				HandleSenseSight(SensedActor);
			}
			break;
		}
		case E_AISense::Sound:
		{
			if (SenseUsed == UAISense_Hearing::StaticClass())
			{
				HandleSenseSound(Stimulus.StimulusLocation);
			}
			break;
		}
		case E_AISense::Damage:
		{
			if (SenseUsed == UAISense_Damage::StaticClass())
			{
				UE_LOG(LogTemp, Warning, TEXT("Damaged by %s"), *SensedActor->GetName());
			}
			break;
		}
		default:
			break;
		}
	}
}

void AEnemy_Base_Controller::SetStateAsPassive()
{
	BlackboardComp->SetValueAsEnum(TEXT("State"), (uint8)EEnemyAIState::Passive);
	CurrentAttackTarget = nullptr;
	BlackboardComp->ClearValue(TEXT("HostileTarget"));
}

void AEnemy_Base_Controller::SetStateAsCombat(AActor* AttackTarget)
{
	BlackboardComp->SetValueAsEnum(TEXT("State"), (uint8)EEnemyAIState::Combat);
	CurrentAttackTarget = AttackTarget;
	BlackboardComp->SetValueAsObject(TEXT("HostileTarget"), AttackTarget);
}

void AEnemy_Base_Controller::SetStateAsInvestigating(FVector PointOfInterest)
{
	BlackboardComp->SetValueAsEnum(TEXT("State"), (uint8)EEnemyAIState::Investigating);
	BlackboardComp->SetValueAsVector(TEXT("PointOfInterest"), PointOfInterest);
}

AActor* AEnemy_Base_Controller::GetAttackTarget()
{
	return CurrentAttackTarget;
}

void AEnemy_Base_Controller::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	for(AActor* SensedActor : UpdatedActors)
	{
		CanSenseActor(SensedActor, E_AISense::Sight);
		CanSenseActor(SensedActor, E_AISense::Damage);
		CanSenseActor(SensedActor, E_AISense::Sound);
	}
}

void AEnemy_Base_Controller::HandleSenseSight(AActor* SensedActor)
{
	if (BlackboardComp->GetValueAsEnum("State") == (uint8)EEnemyAIState::Combat 
		|| BlackboardComp->GetValueAsEnum("State") == (uint8)EEnemyAIState::Stunned || Cast<AEnemy_Base>(SensedActor))	return;

	SetStateAsCombat(SensedActor);
}

void AEnemy_Base_Controller::HandleSenseSound(FVector PointOfInterest)
{
	if (BlackboardComp->GetValueAsEnum("State") == (uint8)EEnemyAIState::Combat
		|| BlackboardComp->GetValueAsEnum("State") == (uint8)EEnemyAIState::Stunned)	return;

	SetStateAsInvestigating(PointOfInterest);
}
