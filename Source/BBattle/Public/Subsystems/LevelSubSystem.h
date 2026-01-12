// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/Subsystem.h"
#include "LevelDataAsset.h"
#include "BBotPlayerCharacter.h"
#include "LevelSubSystem.generated.h"

/**
 * 
 */
UCLASS()
class BBATTLE_API ULevelSubSystem : public USubsystem
{
	GENERATED_BODY()

protected:

	int currentLevel;

	TArray<FVector> spawnLocations;

	UPROPERTY(EditAnywhere, Category = "Ability")
	ULevelDataAsset* levelDataAsset;

	UPROPERTY(EditAnywhere, Category = "Ability")
	ABBotPlayerCharacter* bbotPlayer;

	void GetSpawnPoints();

	void SpawnEnemies();

	void SpawnPlayer();

public:

	UFUNCTION(BlueprintCallable, Category = "Ability")
	FLevelData GetCurrentLevelData();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void InitLevel();

};
