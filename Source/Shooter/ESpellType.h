// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

 UENUM(BlueprintType)
 enum class ESpellType : uint8
 {
    None        UMETA(DisplayName = "None"),
    Damage      UMETA(DisplayName = "Damage"),
    Control     UMETA(DisplayName = "Control"),
    Movement    UMETA(DisplayName = "Movement"),
    Healing     UMETA(DisplayName = "Healing"),
    AoE         UMETA(DisplayName = "Area of Effect")
 };
