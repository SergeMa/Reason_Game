// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWidget.h"
#include "Components\TextBlock.h"
#include "Components\Image.h"
#include "Components\ProgressBar.h"

void UPlayerWidget::SetValues(float CurrentHealth, float MaxHealth)
{
	FString HealthString = FString::Printf(TEXT("Health %.0f/%.0f"), CurrentHealth, MaxHealth);
	HealthTextBlock->SetText(FText::FromString(HealthString));
	HealthProgressBar->SetPercent(CurrentHealth / MaxHealth);
}
