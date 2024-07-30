// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy_Base.h"
#include "ESpellType.h"
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
	UPROPERTY(EditAnywhere)
	float ManaAmount = 30;

	UPROPERTY(EditAnywhere)
	float ManaRegenegation = 0.5f;

	UPROPERTY(EditAnywhere)
	ASpell_Base* CurrentChosenSpell;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ASpell_Base*> KnownSpells;

public:
	UPROPERTY(VisibleAnywhere)
	bool isCastingSpell = false;

	UFUNCTION(BlueprintPure)
	ASpell_Base* GetCurrentChosenSpell();

	UFUNCTION(BlueprintCallable)
	void SetCurrentChosenSpellOfType(ESpellType TypeOfSpell);

	UFUNCTION(BlueprintCallable)
	void SetCurrentChosenSpellOfName(FString SpellName);

	UFUNCTION(BlueprintCallable)
	void CastSpell();
};
