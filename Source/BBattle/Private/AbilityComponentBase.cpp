// Fill out your copyright notice in the Description page of Project Settings.

#include "Abilities/AbilityData.h"
#include "Subsystems/PlayerDataSubSystem.h"
#include "Kismet/GameplayStatics.h"
#include "IntervalWatch.h"
#include "AbilityComponentBase.h"

// Sets default values for this component's properties
UAbilityComponentBase::UAbilityComponentBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UAbilityComponentBase::BeginPlay()
{
	Super::BeginPlay();

	InitIntervalWatch();

	GetOwner()->GetComponents<UAbilityBase>(abilityBaseCollection);

	GEngine->AddOnScreenDebugMessage(-6, 4, FColor::White, "abilityBaseCollection count " + FString::FromInt(abilityBaseCollection.Num()));
}

void UAbilityComponentBase::HandleNextInterval(int32 index)
{
	GEngine->AddOnScreenDebugMessage(-4, 2, FColor::Blue, "UAbilityComponent Interval Index " + FString::FromInt(index));
}

void UAbilityComponentBase::InitIntervalWatch()
{
	intervalWatch = GetOwner()->FindComponentByClass<UIntervalWatch>();

	if (IsValid(intervalWatch))
	{
		GEngine->AddOnScreenDebugMessage(-4, 2, FColor::Blue, "Interval Watch Found");
		intervalWatch->OnNextInterval.BindUObject(this, &UAbilityComponentBase::HandleNextInterval);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-4, 2, FColor::Blue, "Interval Watch Not Found");
	}
}

