// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_Melee.h"
#include "Weapon_Pickup.h"
#include "Enemy_Base.h"
#include "Perception/AISense_Damage.h"

void AWeapon_Melee::HandleCollision()
{
    FVector Start = GetActorLocation();
    FVector ActorDownVector = GetActorUpVector() * -1;
    FVector End = Start + (ActorDownVector * WeaponLength);
    FHitResult HitResult;

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(this);
    CollisionParams.AddIgnoredActor(GetOwner());

    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Pawn, CollisionParams);
    if (GEngine)
    {
        DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f, 0, 2.0f);
    }

    if (bHit)
    {
        AActor* HitActor = HitResult.GetActor();
        if (HitActor && !HitActors.Contains(HitActor))
        {
            HitActors.Add(HitActor);
            if (ACharacter_Base* HitCharacter = Cast<ACharacter_Base>(HitActor))
            {
                UE_LOG(LogTemp, Log, TEXT("Hit Actor: %s"), *HitCharacter->GetName());

                DealDamage(HitCharacter);
                if (AEnemy_Base* HitEnemy = Cast<AEnemy_Base>(HitCharacter))
                {
                    UAISense_Damage::ReportDamageEvent(GetWorld(), HitEnemy, GetOwner(), 
                        Damage, GetActorLocation(), HitResult.Location);
                }
            }
        }
    }
}

void AWeapon_Melee::DropWeapon()
{
    if (!WeaponPickupClass || GetOwner() == nullptr)     return;
   
    DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
    FVector SpawnLocation = GetActorLocation();
    FRotator SpawnRotation = GetActorRotation();
    AWeapon_Pickup* WeaponPickup = GetWorld()->SpawnActor<AWeapon_Pickup>(WeaponPickupClass, SpawnLocation, SpawnRotation);

    this->Destroy();
}
