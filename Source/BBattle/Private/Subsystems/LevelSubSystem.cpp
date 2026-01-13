// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Subsystems/LevelSubSystem.h"

#pragma region Protected


void ULevelSubSystem::GetSpawnPoints()
{
	TArray<AActor*> enemySpawnPoints;
	TArray<AActor*> playerSpawnPoints;

	FVector posVector;

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), levelDataAsset->enemySpawnTag, enemySpawnPoints);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), levelDataAsset->playerSpawnTag, playerSpawnPoints);

	for (int i = 0; i < enemySpawnPoints.Num(); i++)
	{
		posVector = enemySpawnPoints[i]->GetActorLocation();
		enemySpawnLocations.Add(posVector);
	}

	posVector = playerSpawnPoints[0]->GetActorLocation();
	playerSpawnLocation = posVector;

	UE_LOG(LogTemp, Error, TEXT("Spawn count: %s _ %s"), *FString::FromInt(enemySpawnLocations.Num()), *FString::FromInt(playerSpawnPoints.Num()));
}

void ULevelSubSystem::SpawnEnemies()
{
}

void ULevelSubSystem::SpawnPlayer()
{
	AActor* playerActor = UGameplayStatics::GetActorOfClass(GetWorld(), ABBotPlayerCharacter::StaticClass());

	if (IsValid(playerActor))
	{
		playerActor->SetActorLocation(playerSpawnLocation);
	}
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
	SpawnPlayer();
}

void ULevelSubSystem::InitSubsystem(ULevelDataAsset* levelData)
{
	levelDataAsset = levelData;
}
#pragma endregion

