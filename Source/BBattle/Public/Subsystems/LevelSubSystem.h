// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/Subsystem.h"
#include "LevelDataAsset.h"
#include "BBotPlayerCharacter.h"
#include "BBotEnemyPawn.h"
#include "EnemySpawnPoint.h"
#include "LevelSubSystem.generated.h"

/**
 * 
 */

UCLASS()
class BBATTLE_API ULevelSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:

	int currentLevel;

	int defeatedEnemyCount;

	TArray<AEnemySpawnPoint*> enemySpawnPoints;

	FVector playerSpawnLocation;

	ULevelDataAsset* levelDataAsset;

	UPROPERTY(EditAnywhere, Category = "Level")
	AActor* bbotPlayer;

	UWorld* world;

	TArray<ABBotEnemyPawn*> enemyBots;

	void GetSpawnPoints();

	void SpawnEnemies();

	void SpawnPlayer();

	void ToggleActor(AActor* actor, bool value);

	void ClearEnemies();

	void HandleEnemyDefeated();

	UFUNCTION()
	void HandleLevelWin(bool isWin);

public:

	UFUNCTION(BlueprintCallable, Category = "Ability")
	FLevelData GetCurrentLevelData();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void InitLevel();

	void InitSubsystem(ULevelDataAsset* levelData);

	UFUNCTION(BlueprintCallable)
	void DeInitSubsystem();

	UFUNCTION(BlueprintCallable)
	int GetCurrentLevel();

	UFUNCTION(BlueprintCallable)
	void SetCurrentLevel(int value);

	UFUNCTION(BlueprintCallable)
	void HidePlayer();

};
