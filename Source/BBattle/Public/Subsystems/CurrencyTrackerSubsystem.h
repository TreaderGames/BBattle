// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameConfig.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CurrencyTrackerSubsystem.generated.h"

/**
 * 
 */

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCurrencyUpdate);

UCLASS()
class BBATTLE_API UCurrencyTrackerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
protected:

	UGameConfig* gameConfig;

	int32 currencyCount;

public:
	UCurrencyTrackerSubsystem();

	UFUNCTION(BlueprintCallable)
	int32 GetCurrencyCount();

	UFUNCTION(BlueprintCallable)
	void UpdateCurrencyCount(int32 count);

	void InitSubsystem(UGameConfig* config);

	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Ability");
	FOnCurrencyUpdate OnCurrencyUpdate;
};
