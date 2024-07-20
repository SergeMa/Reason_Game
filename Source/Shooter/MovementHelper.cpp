// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementHelper.h"

// Define the static member variable
TMap<ECharacterMovementSpeed, int32> MovementHelper::MovementSpeedMap;

int32 MovementHelper::GetMovementSpeed(ECharacterMovementSpeed MovementSpeed)
{
    return MovementSpeedMap.Contains(MovementSpeed) ? MovementSpeedMap[MovementSpeed] : 200;
}

void MovementHelper::InitializeMovementSpeedMap()
{
    MovementSpeedMap.Add(ECharacterMovementSpeed::Frozen, 0);
    MovementSpeedMap.Add(ECharacterMovementSpeed::Walk, 200);
    MovementSpeedMap.Add(ECharacterMovementSpeed::Investigate, 350);
    MovementSpeedMap.Add(ECharacterMovementSpeed::Run, 500);
}
