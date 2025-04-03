// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class PANGAEA_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:

	//void MakeAttackDecision(APawn* targetPawn);  //AI decision making. Called by PawnTick
	UFUNCTION()
	void PerceptionUpdated(const TArray<AActor*>& UpdatedActors);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UAIPerceptionComponent* AIPerceptionComponent;

	virtual void BeginPlay() override;
};
	
