// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spell_Projectile.generated.h"

class ACharacter_Base;
class UParticleSystemComponent;
class UProjectileMovementComponent;

UCLASS()
class SHOOTER_API ASpell_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpell_Projectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxCollider;

	UPROPERTY(EditAnywhere)
	UParticleSystemComponent* SpellVisuals;

	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere)
	UParticleSystem* SpellHitVisual;

	UPROPERTY(VisibleAnywhere)
	ACharacter_Base* OwnerCharacter;

	UFUNCTION()
	void OnCollisionEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void DealDamage(ACharacter_Base* Victim);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	float Damage = 10;



};
