// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Subsystems/GameStateSubSystem.h"
#include "Subsystems/LevelSubSystem.h"
#include <Subsystems/CurrencyTrackerSubsystem.h>

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

	//UE_LOG(LogTemp, Error, TEXT("Spawn count: %s _ %s"), *FString::FromInt(enemySpawnPoints.Num()), *FString::FromInt(playerSpawnPoints.Num()));
}

void ULevelSubSystem::SpawnEnemies()
{
	TArray<FEnemyData> enemyDataArr = levelDataAsset->levelDataArr[currentLevel].enemyDataArr;
	TArray<AEnemySpawnPoint*> enemySpawnPointsTemp = enemySpawnPoints;

	int randomIndex = 0;

	for (int i = 0; i < enemyDataArr.Num(); i++)
	{
		randomIndex = FMath::RandRange(0, enemySpawnPointsTemp.Num() - 1);

		ABBotEnemyPawn* enemyActor = enemySpawnPointsTemp[randomIndex]->SpawnEnemyBot(enemyDataArr[i]);
		enemyBots.Add(enemyActor);

		FOnDefeated* onDefeated = enemyActor->GetOnDefeated();
		onDefeated->BindUObject(this, &ULevelSubSystem::HandleEnemyDefeated);

		enemySpawnPointsTemp.RemoveAt(randomIndex);
		//UE_LOG(LogTemp, Error, TEXT("SpawnEnemies: %s _ %s"), *FString::FromInt(enemySpawnPointsTemp.Num()), *FString::FromInt(enemySpawnPoints.Num()));
		//UE_LOG(LogTemp, Error, TEXT("SpawnEnemies rand: %s"), *FString::FromInt(randomIndex));
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

		ABBotPlayerCharacter* playerCharacter = Cast<ABBotPlayerCharacter>(bbotPlayer);
		playerCharacter->DoReset();
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
	//UE_LOG(LogTemp, Error, TEXT("ClearEnemies %s"), *FString::FromInt(enemyBots.Num()));
	defeatedEnemyCount = 0;

	if (!enemyBots.IsEmpty())
	{
		for (int i = 0; i < enemyBots.Num(); i++)
		{
			if (IsValid(enemyBots[i])) 
			{
				enemyBots[i]->ClearBeforeDestroy();
				GetWorld()->DestroyActor(enemyBots[i]);
				//UE_LOG(LogTemp, Error, TEXT("ClearEnemies %s"), *FString::FromInt(i));
			}
		}
	}

	enemyBots.Empty();
}

void ULevelSubSystem::HandleEnemyDefeated()
{
	defeatedEnemyCount++;
	UE_LOG(LogTemp, Error, TEXT("HandleEnemyDefeated"));
	if (defeatedEnemyCount >= GetCurrentLevelData().enemyDataArr.Num())
	{
		UGameStateSubSystem* gameStateSubSystem = GetWorld()->GetGameInstance()->GetSubsystem<UGameStateSubSystem>();
		gameStateSubSystem->TriggerGameOver(true);
		//HandleLevelWin();
	}
}

void ULevelSubSystem::HandleLevelWin(bool isWin)
{
	UE_LOG(LogTemp, Error, TEXT("HandleLevelWin"));
	if (isWin) {
		currentLevel++;

		if (currentLevel >= levelDataAsset->levelDataArr.Num())
		{
			currentLevel = 0;
		}

		UCurrencyTrackerSubsystem* currencySubSystem = GetWorld()->GetGameInstance()->GetSubsystem<UCurrencyTrackerSubsystem>();
		currencySubSystem->UpdateCurrencyCount(1);
	}
	else
	{
		currentLevel = 0;
	}
}

#pragma endregion

#pragma region Public

FLevelData ULevelSubSystem::GetCurrentLevelData()
{
	return levelDataAsset->levelDataArr[currentLevel];
}

void ULevelSubSystem::InitLevel()
{
	UGameStateSubSystem* gameStateSubSystem = GetWorld()->GetGameInstance()->GetSubsystem<UGameStateSubSystem>();
	gameStateSubSystem->TriggerGameStart();

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

	UGameStateSubSystem* gameStateSubSystem = GetWorld()->GetGameInstance()->GetSubsystem<UGameStateSubSystem>();
	gameStateSubSystem->OnGameOver.AddDynamic(this, &ULevelSubSystem::HandleLevelWin);
}

void ULevelSubSystem::DeInitSubsystem()
{
	enemySpawnPoints.Empty();
	enemyBots.Empty();
}


int ULevelSubSystem::GetCurrentLevel()
{
	return currentLevel;
}

void ULevelSubSystem::SetCurrentLevel(int value)
{
	currentLevel = 0;
}
void ULevelSubSystem::HidePlayer()
{
	ABBotPlayerCharacter* playerCharacter = Cast<ABBotPlayerCharacter>(bbotPlayer);
	playerCharacter->DoReset();

	bbotPlayer->SetActorLocation(FVector::ForwardVector * 900);
}
#pragma endregion

