// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Mage.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Spell_Base.h"
#include "Spell_Projectile.h"

void AEnemy_Mage::BeginPlay()
{
	Super::BeginPlay();

	if (!Weapon_Class && !KnownSpells.IsEmpty())
	{
		Weapon = GetWorld()->SpawnActor<AWeapon_Base>(KnownSpells[0]);
		Weapon->SetOwner(this);
		Weapon_Disarm_Attach();
	}
}

void AEnemy_Mage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentManaAmount < MaxManaAmount)
	{
		CurrentManaAmount += ManaRegenegation * DeltaTime;
	}
}

void AEnemy_Mage::SetCurrentChosenSpellOfType(ESpellType TypeOfSpell)
{
	if (KnownSpells.Num() == 0) return;

	for(TSubclassOf<ASpell_Base> SpellToSet : KnownSpells)
	{
		
	}
}

void AEnemy_Mage::SetCurrentChosenSpellOfName(FString SpellName)
{
	if (KnownSpells.Num() == 0) return;

	for (TSubclassOf<ASpell_Base> SpellToSet : KnownSpells)
	{

	}
}

void AEnemy_Mage::CastSpell()
{
	ASpell_Base* SpellWeapon = Cast<ASpell_Base>(Weapon);
	if (SpellWeapon == nullptr || GetCharacterMovement()->IsFalling() || CurrentManaAmount < SpellWeapon->ManaCost) return;

	SpellWeapon->CastSpell();
}
