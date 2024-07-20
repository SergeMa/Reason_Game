// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E_AISense.generated.h"

UENUM(BlueprintType)
enum class E_AISense : uint8
{
    None        UMETA(DisplayName = "None"),
    Sight       UMETA(DisplayName = "Sight"),
    Sound       UMETA(DisplayName = "Sound"),
    Damage      UMETA(DisplayName = "Damage"),
};
