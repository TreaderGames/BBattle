// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAttackAbility.h"

void UMeleeAttackAbility::TriggerAbility(FAbilityData abilityData)
{
	Super::TriggerAbility(abilityData);

	if (abilityData.abilityType == abilityType) {
		UE_LOG(LogTemp, Error, TEXT("TriggerAbility"));
	}
}

void UMeleeAttackAbility::MeleeAttackTickNotify()
{
	UE_LOG(LogTemp, Error, TEXT("MeleeAttackTickNotify"));
}
