// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Abilities/AbilityData.h"
#include "PlayerDataAsset.h"
#include "PlayerDataSubSystem.generated.h"

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilitiesUpdated);

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
	
	UFUNCTION(BlueprintCallable)
	void DebugFunction();

	UFUNCTION(BlueprintCallable)
	TArray<FAbilityData> GetAbilityArr();

	UFUNCTION(BlueprintCallable)
	void UpdatePlayerAbilities(TArray<FAbilityData> abilityDataArr);

	UPROPERTY(EditAnywhere, BlueprintAssignable);
	FOnAbilitiesUpdated OnAbilitiesUpdated;

};
