// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/GameStateSubSystem.h"

void UGameStateSubSystem::TriggerGameOver(bool isWin)
{
	//UE_LOG(LogTemp, Error, TEXT("TriggerGameOver %s"), isWin ? TEXT("true") : TEXT("false"));

	if (!gameOverDone)
	{
		OnGameOver.Broadcast(isWin);

		gameOverDone = true;
	}
}

void UGameStateSubSystem::TriggerGameStart()
{
	gameOverDone = false;

	OnGameStart.Broadcast();
}
