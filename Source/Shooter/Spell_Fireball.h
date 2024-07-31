// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell_Base.h"
#include "Spell_Fireball.generated.h"

/**
 * 
 */
class ASpell_Projectile;

UCLASS()
class SHOOTER_API ASpell_Fireball : public ASpell_Base
{
	GENERATED_BODY()
	
protected:
	ASpell_Projectile* CastSpell();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASpell_Projectile> FireballProjectile;

};
