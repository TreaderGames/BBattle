// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Abilities/AbilityData.h"
#include "PlayerDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class BBATTLE_API UPlayerDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "Ability")
	TArray<FAbilityData> defaultAbilities;
};
