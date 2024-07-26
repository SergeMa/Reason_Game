// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Fireball.h"
#include "Spell_Projectile.h"
#include "Kismet/GameplayStatics.h"

void ASpell_Fireball::CastSpell()
{
    if (FireballProjectile)
    {
        FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 100.0f;
        FRotator SpawnRotation = GetActorRotation();

        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator();

        GetWorld()->SpawnActor<ASpell_Projectile>(FireballProjectile, SpawnLocation, SpawnRotation, SpawnParams);
    }
}
