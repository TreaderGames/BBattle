// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "PlayerAbilityComponent.h"


void UPlayerAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(this->GetWorld());
	playerDataSubSystem = GameInstance->GetSubsystem<UPlayerDataSubSystem>();
}

void UPlayerAbilityComponent::HandleNextInterval(int32 index)
{
	Super::HandleNextInterval(index);

	FAbilityData abilityData = playerDataSubSystem->GetInterval(index);

	for (int32 i = 0; i < abilityBaseCollection.Num(); i++)
	{
		abilityBaseCollection[i]->TriggerAbility(abilityData);
	}
}
