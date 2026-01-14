// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelDataAsset.h"
#include "EnemySpawnPoint.generated.h"

UCLASS()
class BBATTLE_API AEnemySpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawnPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Custom")
	TSubclassOf<ABBotEnemyPawn> botEnemySubclass;

	UPROPERTY(EditAnywhere, Category = "Custom")
	AActor* botEnemyTemplate;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AActor* SpawnEnemyBot(FEnemyData enemyData);

};
