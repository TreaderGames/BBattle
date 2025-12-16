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

	//abilityArr = playerDataAsset->defaultAbilities;
	//DebugFunction();
}

void UPlayerDataSubSystem::DebugFunction()
{
	const UEnum* enumPtr = StaticEnum<EAbilityType>();
	FString enumString;
	for (int32 i = 0; i != abilityArr.Num(); ++i)
	{
		enumString = enumPtr->GetNameStringByValue(static_cast<int32>(abilityArr[i].abilityType));
		GEngine->AddOnScreenDebugMessage(-2, 2, FColor::Blue, "Ability Type: " + enumString);
		//UE_LOG(LogTemp, Error, "Ability Type: "+ enumString);
	}
}
