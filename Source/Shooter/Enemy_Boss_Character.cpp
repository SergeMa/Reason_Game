// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Boss_Character.h"
#include "Weapon_Melee.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Enemy_Base_Controller.h"
#include "BehaviorTree/BlackboardComponent.h"


void AEnemy_Boss_Character::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy_Boss_Character::HandleStageTransition()
{
    CurrentStage+=1;
    if (AEnemy_Base_Controller* AIController = Cast<AEnemy_Base_Controller>(GetController()))
    {
        if (UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent())
        {
            BlackboardComp->SetValueAsInt("CurrentStage", CurrentStage);
        }
    }

    if (GEngine)
    {
        FString Message = FString::Printf(TEXT("Current boss stage is %i"), CurrentStage);
        GEngine->AddOnScreenDebugMessage(0, 5, FColor::Blue, Message);
    }
    ChangeStage(CurrentStage);
}

void AEnemy_Boss_Character::EquipWeaponWithIndex(int WeaponIndex)
{
    if (Weapon == WeaponList[WeaponIndex])
    {
        if (AEnemy_Base_Controller* AIController = Cast<AEnemy_Base_Controller>(GetController()))
        {
            if (UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent())
            {
                BlackboardComp->SetValueAsInt("WeaponIndex", (-1));
            }
        }
    }
    else
    {
        if (AEnemy_Base_Controller* AIController = Cast<AEnemy_Base_Controller>(GetController()))
        {
            if (UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent())
            {
                BlackboardComp->SetValueAsInt("WeaponIndex", WeaponIndex);
            }
        }
    }

    Super::EquipWeaponWithIndex(WeaponIndex);
}

void AEnemy_Boss_Character::ChangeStage_Implementation(int StageNum)
{

}