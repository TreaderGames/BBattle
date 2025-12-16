// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponent.h"
#include "IntervalWatch.h"

// Sets default values for this component's properties
UAbilityComponent::UAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	InitIntervalWatch();
}

void UAbilityComponent::HandleNextInterval(int32 index)
{
	GEngine->AddOnScreenDebugMessage(-4, 2, FColor::Blue, "UAbilityComponent Interval Index " + FString::FromInt(index));
}

void UAbilityComponent::InitIntervalWatch()
{
	intervalWatch = GetOwner()->FindComponentByClass<UIntervalWatch>();

	if (IsValid(intervalWatch))
	{
		GEngine->AddOnScreenDebugMessage(-4, 2, FColor::Blue, "Interval Watch Found");
		intervalWatch->OnNextInterval.BindUObject(this, &UAbilityComponent::HandleNextInterval);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-4, 2, FColor::Blue, "Interval Watch Not Found");
	}
}

