// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AI_PatrolRoute.generated.h"

UCLASS()
class SHOOTER_API AAI_PatrolRoute : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAI_PatrolRoute();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void IncrementPatrolRoute();

	UFUNCTION(BlueprintPure)
	FVector GetSplinePointAsWorldCoords();

private:
	UPROPERTY(EditAnywhere)
	class USplineComponent* PatrolPath;

	UPROPERTY(EditAnywhere)
	bool ShouldGoFromFirstIndex = false;

	UPROPERTY(VisibleAnywhere)
	int PatrolIndex = 0;

	UPROPERTY(VisibleAnywhere)
	int PatrolDirection = 1;
};