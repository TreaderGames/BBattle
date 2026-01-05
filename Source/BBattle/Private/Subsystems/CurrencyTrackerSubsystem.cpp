// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/CurrencyTrackerSubsystem.h"
#include "Subsystems/CurrencyTrackerSubsystem.h"

UCurrencyTrackerSubsystem::UCurrencyTrackerSubsystem()
{
}

int32 UCurrencyTrackerSubsystem::GetCurrencyCount()
{
	return currencyCount;
}

void UCurrencyTrackerSubsystem::UpdateCurrencyCount(int32 count)
{
	currencyCount = FMath::Clamp(currencyCount + count, 0, currencyCount + count);

	OnCurrencyUpdate.Broadcast();
}

void UCurrencyTrackerSubsystem::InitSubsystem(UGameConfig* config)
{
	gameConfig = config;
	currencyCount = gameConfig->defaultCredits;

	UE_LOG(LogTemp, Error, TEXT("InitSubsystem Credits"));
}
