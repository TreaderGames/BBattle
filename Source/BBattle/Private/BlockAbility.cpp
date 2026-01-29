// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockAbility.h"

void UBlockAbility::TriggerAbility(FAbilityData abilityData)
{
	if (abilityData.abilityType == abilityType)
	{
		ToggleSheild(true);
	}
	else if(isShieldActive)
	{
		ToggleSheild(false);
	}
}

void UBlockAbility::BeginPlay()
{
	PrimaryComponentTick.bCanEverTick = false;
	isShieldActive = false;

	InitReferences();
}

void UBlockAbility::ToggleSheild(bool value)
{
	isShieldActive = value;

	for (int32 i = 0; i < allColliders.Num(); i++)
	{
		allColliders[i]->SetCollisionProfileName(value ? inactivePreset : activePreset, true);
	}
}

void UBlockAbility::InitReferences()
{
	GetOwner()->GetComponents<UShapeComponent>(allColliders);

	/*for (int32 i = 0; i < allColliders.Num(); i++)
	{
		UE_LOG(LogTemp, Error, TEXT("UBlockAbility allColliders name %s"), *allColliders[i]->GetFName().ToString());
	}

	UE_LOG(LogTemp, Error, TEXT("UBlockAbility allColliders length %s"), *FString::FromInt(allColliders.Num()));*/
}
