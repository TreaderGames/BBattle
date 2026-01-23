// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameStateSubSystem.generated.h"

/**
 * 
 */
UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameOver, bool, isWin);

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStart);

UCLASS()
class BBATTLE_API UGameStateSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:

	bool gameOverDone;

public:

	void TriggerGameOver(bool isWin);

	void TriggerGameStart();
	
	UPROPERTY(EditAnywhere, BlueprintAssignable);
	FOnGameOver OnGameOver;

	UPROPERTY(EditAnywhere, BlueprintAssignable);
	FOnGameStart OnGameStart;
};
