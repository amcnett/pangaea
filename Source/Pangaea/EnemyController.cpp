// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "Enemy.h"

//void AEnemyController::MakeAttackDecision(APawn* targetPawn)
//{
//	auto controlledCharacter = Cast<AEnemy>(GetPawn());
//	auto dist = FVector::Dist2D(targetPawn->GetActorLocation(), GetPawn()->GetTargetLocation());
//	//UE_LOG(LogTemp, Warning, TEXT("Distance=%d"), dist);
//	if (dist <= controlledCharacter->AttackRange && controlledCharacter->CanAttack())
//	{
//		controlledCharacter->Attack();
//	}
//}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn)
	{
		AIPerceptionComponent = ControlledPawn->FindComponentByClass<UAIPerceptionComponent>();
	}
	if (AIPerceptionComponent)
	{
		UE_LOG(LogTemp, Log, TEXT("Binding see function"));
		AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &AEnemyController::PerceptionUpdated);
	}
}

void AEnemyController::PerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	// Logic for handling perception updates
	UE_LOG(LogTemp, Log, TEXT("I sense stuff!"));
	for (AActor* Actor : UpdatedActors)
	{
		if (!Actor) continue;
		APawn* DetectedPawn = Cast<APawn>(Actor);
		APawn* ControlledPawn = GetPawn();
		AEnemy* EnemyPawn = Cast<AEnemy>(ControlledPawn);
		if (DetectedPawn) {
			auto dist = FVector::Dist2D(DetectedPawn->GetActorLocation(), GetTargetLocation());
			//UE_LOG(LogTemp, Warning, TEXT("Distance=%d"), dist);
			UE_LOG(LogTemp, Log, TEXT("Considering attacking"));
			if (dist <= EnemyPawn->AttackRange && EnemyPawn->CanAttack())
			{
				UE_LOG(LogTemp, Log, TEXT("Attack!!!!!!!!"));
				EnemyPawn->Attack();
			}
			else { //chase!
				MoveToActor(DetectedPawn, 90.0f);
			}
		}
	}
}
