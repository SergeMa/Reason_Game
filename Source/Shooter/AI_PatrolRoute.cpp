// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_PatrolRoute.h"
#include "Components/SplineComponent.h"

// Sets default values
AAI_PatrolRoute::AAI_PatrolRoute()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PatrolPath = CreateDefaultSubobject<USplineComponent>(TEXT("Patrol spline"));
	RootComponent = PatrolPath;
}

// Called when the game starts or when spawned
void AAI_PatrolRoute::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_PatrolRoute::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAI_PatrolRoute::IncrementPatrolRoute()
{
	PatrolIndex += PatrolDirection;

	if (PatrolIndex >= PatrolPath->GetNumberOfSplinePoints()-1)
	{
		PatrolDirection = -1;
	}
	else if(PatrolIndex <= 0)
	{
		PatrolDirection = 1;
	}
}

FVector AAI_PatrolRoute::GetSplinePointAsWorldCoords()
{
	return PatrolPath->GetLocationAtSplinePoint(PatrolIndex, ESplineCoordinateSpace::World);
}

