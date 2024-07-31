// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Fireball.h"
#include "Spell_Projectile.h"
#include "Kismet/GameplayStatics.h"
#include "Character_Base.h"

ASpell_Projectile* ASpell_Fireball::CastSpell()
{
    if (!FireballProjectile) return nullptr;

    FVector SpawnLocation = GetActorLocation();
    FRotator SpawnRotation = GetOwner()->GetActorRotation();
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = GetOwner();
    SpawnParams.Instigator = GetOwner()->GetInstigator();

    ASpell_Projectile* Projectile = GetWorld()->SpawnActor<ASpell_Projectile>(FireballProjectile, SpawnLocation, SpawnRotation, SpawnParams);
    Projectile->CasterCharacter = Cast<ACharacter_Base>(GetOwner());

    return Projectile;
}
