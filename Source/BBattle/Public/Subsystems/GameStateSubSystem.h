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

UCLASS()
class BBATTLE_API UGameStateSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	void TriggerGameOver(bool isWin);
	
	UPROPERTY(EditAnywhere, BlueprintAssignable);
	FOnGameOver OnGameOver;
};
