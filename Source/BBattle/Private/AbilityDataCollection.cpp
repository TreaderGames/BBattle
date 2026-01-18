// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityDataCollection.h"

FAbilityData UAbilityDataCollection::GetAbilityDataByType(EAbilityType abilityType)
{
	for (int i = 0; i < abilityCollection.Num(); i++)
	{
		if (abilityCollection[i].abilityType == abilityType) {
			return abilityCollection[i];
		}
	}

	return FAbilityData();
}
