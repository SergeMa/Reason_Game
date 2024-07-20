// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ECharacterMovementSpeed : uint8
{
    Frozen          UMETA(DisplayName = "Frozen"),
    Walk            UMETA(DisplayName = "Walk"),
    Investigate     UMETA(DisplayName = "Investigate"),
    Run             UMETA(DisplayName = "Run")
};
