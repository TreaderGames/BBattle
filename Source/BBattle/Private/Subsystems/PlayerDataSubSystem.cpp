// Fill out your copyright notice in the Description page of Project Settings.

#include "Abilities/AbilityData.h"
#include "Subsystems/PlayerDataSubSystem.h"
//#include "PlayerDataSubSystem.h"

UPlayerDataSubSystem::UPlayerDataSubSystem()
{
}

void UPlayerDataSubSystem::GetInterval(int index)
{
}

void UPlayerDataSubSystem::SetInterval(FAbilityData abilityData, int index)
{
}

void UPlayerDataSubSystem::InitSubsystem(UPlayerDataAsset* playerDataAsset)
{
	GEngine->AddOnScreenDebugMessage(-2, 2, FColor::Blue, "UPlayerDataSubSystem Ready 2");
}
