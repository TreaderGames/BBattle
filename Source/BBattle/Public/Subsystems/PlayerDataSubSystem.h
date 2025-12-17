// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Abilities/AbilityData.h"
#include "PlayerDataAsset.h"
#include "PlayerDataSubSystem.generated.h"

/*
 SetInterval(AbilityData data, int index);
GetInterval(int index)
TArray<AbilityData> abilityArr;
TArray<AbilityData> defaultAbilities;
 */

UCLASS()
class BBATTLE_API UPlayerDataSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
protected:
	TArray<FAbilityData> abilityArr;

public:
	UPlayerDataSubSystem();

	FAbilityData GetInterval(int index);

	void SetInterval(FAbilityData abilityData, int index);

	void InitSubsystem(UPlayerDataAsset* playerDataAsset);
	
	void DebugFunction();
};
