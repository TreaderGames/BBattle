// Fill out your copyright notice in the Description page of Project Settings.

#include "Sound/MusicSystemActor.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"

// Sets default values
AMusicSystemActor::AMusicSystemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	audioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
}

// Called when the game starts or when spawned
void AMusicSystemActor::BeginPlay()
{
	Super::BeginPlay();

    PlayAudio(EMusicType::MainMenu);
}

void AMusicSystemActor::PlayAudio(EMusicType musicType)
{
    if (IsValid(audioComponent)) {
        for (const FMusicData& entry : musicEntries)
        {
            if (entry.musicType == musicType && entry.soundBase)
            {
                audioComponent->SetSound(entry.soundBase);
                audioComponent->Play();
            }
        }
    }
}

