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
	//if (!IsValid(bbotEnemyPawnTemplate))
	//{
	//	bbotEnemyPawnTemplate = UGameplayStatics::GetActorOfClass(GetWorld(), ABBotEnemyPawn::StaticClass());
	//}

	ClearEnemies();

	TArray<FEnemyData> enemyDataArr = levelDataAsset->levelDataArr[currentLevel].enemyDataArr;

	//ToggleActor(bbotEnemyPawnTemplate, false);
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
	GetSpawnPoints();
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

