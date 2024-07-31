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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Casting")
	TArray<TSubclassOf<ASpell_Base>> KnownSpells;

	UPROPERTY(EditAnywhere, Category = "Spell Casting")
	float MaxManaAmount = 30;

	UPROPERTY(VisibleAnywhere, Category = "Spell Casting")
	float CurrentManaAmount = MaxManaAmount;

	UPROPERTY(EditAnywhere, Category = "Spell Casting")
	float ManaRegenegation = 0.5f;

public:
	UFUNCTION(BlueprintCallable)
	void SetCurrentChosenSpellOfType(ESpellType TypeOfSpell);

	UFUNCTION(BlueprintCallable)
	void SetCurrentChosenSpellOfName(FString SpellName);

	UFUNCTION(BlueprintCallable)
	void CastSpell();
};
