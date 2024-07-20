// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ECharacterMovementSpeed.h"

/**
 * 
 */
class SHOOTER_API MovementHelper
{
public:

    static TMap<ECharacterMovementSpeed, int32> MovementSpeedMap;

    static void InitializeMovementSpeedMap();
    static int32 GetMovementSpeed(ECharacterMovementSpeed MovementSpeed);
};
