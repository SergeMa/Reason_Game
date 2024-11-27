// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BossWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UBossWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* HealthTextBlock;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* HealthProgressBar;

	UFUNCTION(BlueprintCallable)
	void SetValues(float CurrentHealth, float MaxHealth);
};
