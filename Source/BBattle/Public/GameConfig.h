// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameConfig.generated.h"

/**
 * 
 */
UCLASS()
class BBATTLE_API UGameConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	int32 maxIntervals;

	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	int32 defaultIntervalDuration;


	UPROPERTY(EditDefaultsOnly, Category = "Currency")
	int32 defaultCredits;
};
