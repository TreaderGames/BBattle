// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"
#include "PlayerDataAsset.h"
#include "Subsystems/PlayerDataSubSystem.h"


UMainGameInstance::UMainGameInstance()
{
	UE_LOG(LogTemp, Error, TEXT("UMainGameInstance Instance Constructed"));
}

void UMainGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Error, TEXT("Game Instance Init"));
	InitSubSystems();
}

void UMainGameInstance::InitSubSystems()
{
	UPlayerDataSubSystem* playerDataSubSystem = this->GetSubsystem<UPlayerDataSubSystem>();
	UE_LOG(LogTemp, Error, TEXT("Game Instance InitSubSystems"));
	if (IsValid(playerDataSubSystem))
	{
		UE_LOG(LogTemp, Error, TEXT("Game Instance InitSubSystems IsValid"));
		playerDataSubSystem->InitSubsystem(playerDataAsset);
		GEngine->AddOnScreenDebugMessage(-2, 2, FColor::Blue, "UPlayerDataSubSystem Ready");
	}
}
