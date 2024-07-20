// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "E_AISense.h"
#include "Enemy_Base_Controller.generated.h"

class UBehaviourTree;
class AAI_PatrolRoute;
class UAIPerceptionComponent;
class UBlackboardComponent;

UCLASS()
class SHOOTER_API AEnemy_Base_Controller : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void OnPossess(APawn* InPawn) override;

public:
	virtual void Tick(float DeltaSeconds) override;
	bool isDead() const;

	UFUNCTION(BlueprintCallable)
	void CanSenseActor(AActor* SencedActor, E_AISense Sense);

	UFUNCTION(BlueprintCallable)
	void SetStateAsPassive();

	UFUNCTION(BlueprintCallable)
	void SetStateAsCombat(AActor* AttackTarget);

	UFUNCTION(BlueprintCallable)
	void SetStateAsInvestigating(FVector PointOfInterest);

	UFUNCTION(BlueprintPure)
	AActor* GetAttackTarget();

private:
	UPROPERTY(VisibleAnywhere)
	AActor* CurrentAttackTarget;

	UAIPerceptionComponent* PerceptionComp;
	UBlackboardComponent* BlackboardComp;

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* AIBehaviorTree;

	UFUNCTION()
	void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors);

	UFUNCTION()
	void HandleSenseSight(AActor* SensedActor);

	UFUNCTION()
	void HandleSenseSound(FVector PointOfInterest);

};
