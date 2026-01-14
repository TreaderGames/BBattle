// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Subsystems/LevelSubSystem.h"

#pragma region Protected


void ULevelSubSystem::GetSpawnPoints()
{
	TArray<AActor*> playerSpawnPoints;
	TArray<AActor*> enemySpawnActors;

	FVector posVector;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawnPoint::StaticClass(), enemySpawnActors);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), levelDataAsset->playerSpawnTag, playerSpawnPoints);

	enemySpawnPoints.Empty();
	for (int i = 0; i < enemySpawnActors.Num(); i++)
	{
		AEnemySpawnPoint* enemySpawnPoint = Cast<AEnemySpawnPoint>(enemySpawnActors[i]);
		enemySpawnPoints.Add(enemySpawnPoint);
	}

	posVector = playerSpawnPoints[0]->GetActorLocation();
	playerSpawnLocation = posVector;

	UE_LOG(LogTemp, Error, TEXT("Spawn count: %s _ %s"), *FString::FromInt(enemySpawnPoints.Num()), *FString::FromInt(playerSpawnPoints.Num()));
}

void ULevelSubSystem::SpawnEnemies()
{
	ClearEnemies();

	TArray<FEnemyData> enemyDataArr = levelDataAsset->levelDataArr[currentLevel].enemyDataArr;

	for (int i = 0; i < enemyDataArr.Num(); i++)
	{
		if (i < enemySpawnPoints.Num())
		{
			AActor* enemyActor = enemySpawnPoints[i]->SpawnEnemyBot(enemyDataArr[i]);
			enemyBots.Add(enemyActor);
		}
	}
}

void ULevelSubSystem::SpawnPlayer()
{
	if (!IsValid(bbotPlayer))
	{
		bbotPlayer = UGameplayStatics::GetActorOfClass(GetWorld(), ABBotPlayerCharacter::StaticClass());
	}

	if (IsValid(bbotPlayer))
	{	
		bbotPlayer->SetActorLocation(playerSpawnLocation);
	}
}

void ULevelSubSystem::ToggleActor(AActor* actor, bool value)
{
	if (IsValid(actor)) {
		actor->SetActorHiddenInGame(!value);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ToggleActor Actor not valid"));
	}
}

void ULevelSubSystem::ClearEnemies()
{
	for (int i = 0; i < enemyBots.Num(); i++)
	{
		enemyBots[i]->Destroy();
	}

	enemyBots.Empty();
}

#pragma endregion

#pragma region Public

FLevelData ULevelSubSystem::GetCurrentLevelData()
{
	return FLevelData();
}

void ULevelSubSystem::InitLevel()
{
	ClearEnemies();

	if (enemySpawnPoints.IsEmpty()) {
		GetSpawnPoints();
	}

	SpawnPlayer();
	SpawnEnemies();
}

void ULevelSubSystem::InitSubsystem(ULevelDataAsset* levelData)
{
	levelDataAsset = levelData;
	currentLevel = 0;
	world = GetWorld();
}
#pragma endregion

