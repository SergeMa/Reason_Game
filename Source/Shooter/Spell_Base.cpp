// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Base.h"

// Sets default values
ASpell_Base::ASpell_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpell_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpell_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpell_Base::CastSpell()
{
	UE_LOG(LogTemp, Error, TEXT("No implementation for CastSpell given!"));
}

