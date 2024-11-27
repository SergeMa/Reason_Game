// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Boss_Controller.h"
#include "Enemy_Boss_Character.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"

void AEnemy_Boss_Controller::OnPossess(APawn* InPawn)
{
	if (!AIBehaviorTree) return;

	Super::OnPossess(InPawn);
	if (AEnemy_Boss_Character* EnemyBoss = Cast<AEnemy_Boss_Character>(GetPawn()))
	{
		BlackboardComp->SetValueAsFloat(TEXT("AttackMeleeRadius"), EnemyBoss->AttackMeleeRadius);
		BlackboardComp->SetValueAsFloat(TEXT("DefendMeleeRadius"), EnemyBoss->DefenceMeleeRadius);
		BlackboardComp->SetValueAsFloat(TEXT("AttackRangedRadius"), EnemyBoss->AttackRangedRadius);
		BlackboardComp->SetValueAsFloat(TEXT("DefendRangedRadius"), EnemyBoss->DefenceRangedRadius);
	}
}

void AEnemy_Boss_Controller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AEnemy_Boss_Controller::SetStateAsCombat(AActor* AttackTarget)
{
	if (AEnemy_Boss_Character* EnemyBoss = Cast<AEnemy_Boss_Character>(GetPawn()))
	{
		EnemyBoss->CreateBossWidget();
	}

	Super::SetStateAsCombat(AttackTarget);
}
