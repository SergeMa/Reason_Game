// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsWieldingWeapon.h"
#include "Enemy_Base.h"
#include "WeaponType.h"
#include "AIController.h"

UBTD_IsWieldingWeapon::UBTD_IsWieldingWeapon()
{
	NodeName = "Is wielding weapon";
}

bool UBTD_IsWieldingWeapon::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr) return false;

	if (AEnemy_Base* OwnerPawn = Cast<AEnemy_Base>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		return OwnerPawn->GetWeaponType() != EWeaponType::WT_None;
	}

	return false;
}
