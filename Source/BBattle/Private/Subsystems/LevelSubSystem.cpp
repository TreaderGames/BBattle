// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Subsystems/LevelSubSystem.h"

#pragma region Protected


void ULevelSubSystem::GetSpawnPoints()
{
	TArray<AActor*> enemySpawnPoints;
	TArray<AActor*> playerSpawnPoints;

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), levelDataAsset->enemySpawnTag, enemySpawnPoints);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), levelDataAsset->playerSpawnTag, playerSpawnPoints);

	UE_LOG(LogTemp, Error, TEXT("Spawn count"));
	UE_LOG(LogTemp, Error, TEXT("Spawn count: %s _ %s"), *FString::FromInt(enemySpawnPoints.Num()), *FString::FromInt(playerSpawnPoints.Num()));
}

void ULevelSubSystem::SpawnEnemies()
{
}

void ULevelSubSystem::SpawnPlayer()
{
}

#pragma endregion

#pragma region Public

FLevelData ULevelSubSystem::GetCurrentLevelData()
{
	return FLevelData();
}

void ULevelSubSystem::InitLevel()
{
	GetSpawnPoints();
}

void ULevelSubSystem::InitSubsystem(ULevelDataAsset* levelData)
{
	levelDataAsset = levelData;
}
#pragma endregion

