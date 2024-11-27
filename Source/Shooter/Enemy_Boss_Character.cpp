// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Boss_Character.h"
#include "Weapon_Melee.h"
#include "BehaviorTree\BehaviorTree.h"
#include "Enemy_Base_Controller.h"
#include "BehaviorTree\BlackboardComponent.h"
#include "UI\BossWidget.h"


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

float AEnemy_Boss_Character::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    float DamageTaken = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
    if (BossWidget)
    {
        BossWidget->SetValues(Health, MaxHealth);
    }

    return DamageTaken;
}

void AEnemy_Boss_Character::CreateBossWidget()
{
    if (!BossWidgetClass || BossWidget) return;

    if (BossWidget = CreateWidget<UBossWidget>(GetWorld()->GetFirstPlayerController(), BossWidgetClass))
    {
        BossWidget->AddToViewport();
        BossWidget->SetValues(Health, MaxHealth);
    }
}

void AEnemy_Boss_Character::DestroyBossWidget()
{
    if (BossWidget)
    {
        BossWidget->RemoveFromViewport();
        BossWidget = nullptr;
    }
}

void AEnemy_Boss_Character::Die()
{
    DestroyBossWidget();
    Super::Die();
}

void AEnemy_Boss_Character::ChangeStage_Implementation(int StageNum)
{
    if (GEngine)
    {
        FString Message = FString::Printf(TEXT("Stage switched to %i"), CurrentStage + 1);
        GEngine->AddOnScreenDebugMessage(0, 5, FColor::Blue, Message);
    }
}