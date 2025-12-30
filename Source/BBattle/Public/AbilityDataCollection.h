// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Abilities/AbilityData.h"
#include "AbilityDataCollection.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class BBATTLE_API UAbilityDataCollection : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability");
	TArray<FAbilityData> abilityCollection;
};
