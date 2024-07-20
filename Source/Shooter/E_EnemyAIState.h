// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E_EnemyAIState.generated.h"

UENUM(BlueprintType)
enum class EEnemyAIState : uint8
{
    Passive         UMETA(DisplayName = "Passive"),
    Investigating   UMETA(DisplayName = "Investigating"),
    Combat          UMETA(DisplayName = "Combat"),
    Stunned         UMETA(DisplayName = "Stunned"),
    Dead            UMETA(DisplayName = "Dead")
};