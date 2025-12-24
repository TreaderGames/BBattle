// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameConfig.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CurrencyTrackerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class BBATTLE_API UCurrencyTrackerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
protected:

	UGameConfig* gameConfig;

	int32 currencyCount;

public:
	UCurrencyTrackerSubsystem();

	int32 GetCurrencyCount();

	void UpdateCurrencyCount(int32 count);

	void InitSubsystem(UGameConfig* config);

};
