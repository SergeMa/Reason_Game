// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spell_Base.generated.h"

UCLASS()
class SHOOTER_API ASpell_Base : public AActor
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

	UFUNCTION(BlueprintCallable, Category = "Spell")
	virtual void CastSpell();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell")
	FString SpellName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell")
	float Cooldown = 1;

};
