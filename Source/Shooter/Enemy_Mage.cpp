// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Mage.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Spell_Base.h"

ASpell_Base* AEnemy_Mage::GetCurrentChosenSpell()
{
	return CurrentChosenSpell;
}

void AEnemy_Mage::SetCurrentChosenSpellOfType(ESpellType TypeOfSpell)
{
	if (KnownSpells.Num() == 0) return;

	for(ASpell_Base* SpellToSet : KnownSpells)
	{
		if (SpellToSet->SpellType == TypeOfSpell)
		{
			CurrentChosenSpell = SpellToSet;
		}
	}
}

void AEnemy_Mage::SetCurrentChosenSpellOfName(FString SpellName)
{
	if (KnownSpells.Num() == 0) return;

	for (ASpell_Base* SpellToSet : KnownSpells)
	{
		if (SpellToSet->SpellName == SpellName)
		{
			CurrentChosenSpell = SpellToSet;
		}
	}
}

void AEnemy_Mage::CastSpell()
{
	if (CurrentChosenSpell == nullptr || isCastingSpell || bIsAttacking || GetCharacterMovement()->IsFalling() || ManaAmount < CurrentChosenSpell->ManaCost) return;

	CurrentChosenSpell->CastSpell();
}
