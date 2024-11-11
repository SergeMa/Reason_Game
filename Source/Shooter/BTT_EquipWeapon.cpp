// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_EquipWeapon.h"
#include "Character_Base.h"
#include "AIController.h"

UBTT_EquipWeapon::UBTT_EquipWeapon()
{
	NodeName = "WeaponEquip_Unequip";
}

EBTNodeResult::Type UBTT_EquipWeapon::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr) return EBTNodeResult::Failed;
	ACharacter_Base* OwnerChar = Cast<ACharacter_Base>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerChar)
	{
		OwnerChar->Weapon_Equip();
		EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
