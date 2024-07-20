// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponType.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
    WT_None     UMETA(DisplayName = "None"),
    WT_Sword    UMETA(DisplayName = "Sword"),
    WT_Axe      UMETA(DisplayName = "Axe"),
    WT_Bow      UMETA(DisplayName = "Bow"),
    WT_Dagger   UMETA(DisplayName = "Dagger"),
    WT_Magic    UMETA(DisplayName = "Magic")
};