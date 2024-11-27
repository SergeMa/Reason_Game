// Fill out your copyright notice in the Description page of Project Settings.


#include "BossWidget.h"
#include "Components\TextBlock.h"
#include "Components\ProgressBar.h"

void UBossWidget::SetValues(float CurrentHealth, float MaxHealth)
{
	FString HealthString = FString::Printf(TEXT("Boss Health %.0f/%.0f"), CurrentHealth, MaxHealth);
	HealthTextBlock->SetText(FText::FromString(HealthString));
	HealthProgressBar->SetPercent(CurrentHealth / MaxHealth);
}