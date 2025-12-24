// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsystems/PlayerDataSubSystem.h"
#include "Abilities/AbilityData.h"
//#include "PlayerDataSubSystem.h"

UPlayerDataSubSystem::UPlayerDataSubSystem()
{
}

FAbilityData UPlayerDataSubSystem::GetInterval(int index)
{
	if (abilityArr.Num() > index)
	{
		GEngine->AddOnScreenDebugMessage(-6, 5, FColor::Blue, "GetInterval Interval Index " + FString::FromInt(index));
		return abilityArr[index];
	}

	return FAbilityData();
}

void UPlayerDataSubSystem::SetInterval(FAbilityData abilityData, int index)
{
}

void UPlayerDataSubSystem::InitSubsystem(UPlayerDataAsset* playerDataAsset)
{
	GEngine->AddOnScreenDebugMessage(-2, 2, FColor::Blue, "UPlayerDataSubSystem Ready 2");
	if (IsValid(playerDataAsset)) 
	{
		abilityArr = playerDataAsset->defaultAbilities;
		//DebugFunction();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("playerDataAsset not found"));
	}
}

void UPlayerDataSubSystem::DebugFunction()
{
	const UEnum* enumPtr = StaticEnum<EAbilityType>();
	FString enumString;
	for (int32 i = 0; i != abilityArr.Num(); ++i)
	{
		enumString = enumPtr->GetNameStringByValue(static_cast<int32>(abilityArr[i].abilityType));
		GEngine->AddOnScreenDebugMessage(i, 2, FColor::Blue, "Ability Type: " + enumString);
		//UE_LOG(LogTemp, Error, "Ability Type: "+ enumString);
	}
}
