// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundDataAsset.h"
#include "MusicType.h"
#include "MusicSystemActor.generated.h"

//USTRUCT()
//struct FMusicData
//{
//	GENERATED_BODY()
//
//public:
//	UPROPERTY(EditAnywhere, Category = "Music")
//	EMusicType musicType = EMusicType::MainMenu;
//
//	UPROPERTY(EditAnywhere, Category = "Music")
//	TObjectPtr<USoundBase> soundBase;
//};

UCLASS()
class BBATTLE_API AMusicSystemActor : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AMusicSystemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*UPROPERTY(EditAnywhere, Category = "Audio Custom");
	FMusicData musicData;*/
	//UPROPERTY(EditAnywhere, Category = "Music")
	//TArray<FMusicData> musicEntries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
	TObjectPtr<USoundDataAsset> soundDataAsset;

	UPROPERTY(EditAnywhere, Category = "Music")
	EMusicType defaultMusic;

	UPROPERTY(VisibleAnywhere, Category = "Music")
	UAudioComponent* audioComponent;

public:	

	UFUNCTION(BlueprintCallable)
	void PlayAudio(EMusicType musicType);
};