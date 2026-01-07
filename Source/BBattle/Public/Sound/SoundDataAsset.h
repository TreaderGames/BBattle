// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MusicType.h"
#include "Engine/DataAsset.h"
#include "SoundDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FMusicData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Music")
	EMusicType musicType = EMusicType::MainMenu;

	UPROPERTY(EditAnywhere, Category = "Music")
	TObjectPtr<USoundBase> soundBase;
};

UCLASS()
class BBATTLE_API USoundDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Music")
	TArray<FMusicData> soundEntries;
};
