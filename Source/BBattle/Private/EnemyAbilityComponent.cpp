// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAbilityComponent.h"

void UEnemyAbilityComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UEnemyAbilityComponent::HandleNextInterval(int32 index)
{
	Super::HandleNextInterval(index);

	FAbilityData abilityData = abilityArr[index];

	//GEngine->AddOnScreenDebugMessage(-5, 2, FColor::Blue, "UEnemyAbilityComponent Interval Index " + FString::FromInt(index));
	//GEngine->AddOnScreenDebugMessage(-7, 2, FColor::Blue, "UEnemyAbilityComponent abilityBaseCollection " + FString::FromInt(abilityBaseCollection.Num()));

	for (int32 i = 0; i < abilityBaseCollection.Num(); i++)
	{
		abilityBaseCollection[i]->TriggerAbility(abilityData);
	}
}
