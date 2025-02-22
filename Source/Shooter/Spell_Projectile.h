// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spell_Projectile.generated.h"

class ACharacter_Base;
class UParticleSystemComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class SHOOTER_API ASpell_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpell_Projectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* BoxCollider;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditDefaultsOnly)
	UParticleSystemComponent* SpellVisuals;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Damage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ACharacter_Base* CasterCharacter;

	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere)
	UParticleSystem* SpellHitVisual;

	UFUNCTION()
	void OnCollisionEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void DealDamage(ACharacter_Base* Victim);

public:
	UFUNCTION()
	void InitializeProjectile(ACharacter_Base* CasterCharacterInput, float DamageInput);

	UFUNCTION(BlueprintNativeEvent)
	void SpellAfterEffect(ACharacter_Base* Victim);
};
