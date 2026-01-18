// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Abilities/AbilityData.h"
#include "LevelDataAsset.generated.h"


USTRUCT(BlueprintType)
struct FEnemyData
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	TArray<FAbilityData> abilityArr;
};

USTRUCT(BlueprintType)
struct FLevelData
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	TArray<FEnemyData> enemyDataArr;
};

UCLASS(BlueprintType)
class BBATTLE_API ULevelDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "Ability")
	TArray <FLevelData> levelDataArr;

	UPROPERTY(EditAnywhere, Category = "Level")
	FName enemySpawnTag;

	UPROPERTY(EditAnywhere, Category = "Level")
	FName playerSpawnTag;
};
