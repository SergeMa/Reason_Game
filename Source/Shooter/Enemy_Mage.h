// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy_Base.h"
#include "Enemy_Mage.generated.h"

/**
 * 
 */
class ASpell_Base;

UCLASS()
class SHOOTER_API AEnemy_Mage : public AEnemy_Base
{
	GENERATED_BODY()
	
protected:
	List<TSubclassOf<ASpell_Base>> KnownSpells;

};
