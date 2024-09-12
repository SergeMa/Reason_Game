// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ESpellType.h"
#include "Weapon_Base.h"
#include "Spell_Base.generated.h"

class ASpell_Projectile;

UCLASS()
class SHOOTER_API ASpell_Base : public AWeapon_Base
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpell_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	class UParticleSystemComponent* SpellParticles;

	UFUNCTION(BlueprintCallable)
	virtual void CastSpell();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString SpellName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ESpellType SpellType = ESpellType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ManaCost = 1;

};
