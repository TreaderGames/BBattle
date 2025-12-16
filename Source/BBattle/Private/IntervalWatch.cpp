// Fill out your copyright notice in the Description page of Project Settings.


#include "IntervalWatch.h"

// Sets default values for this component's properties
UIntervalWatch::UIntervalWatch()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UIntervalWatch::BeginPlay()
{
	Super::BeginPlay();

	ResetValue();
}


// Called every frame
void UIntervalWatch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateTick(DeltaTime);
}

void UIntervalWatch::ResetValue()
{
	intervalDelta = 0;
	intervalIndex = 0;

	intervalDuration = gameConfig->defaultIntervalDuration;
}

void UIntervalWatch::UpdateTick(float delta)
{
	intervalDelta += delta;

	if (intervalDelta >= intervalDuration)
	{
		intervalDelta = 0;
		intervalIndex = (intervalIndex + 1) % gameConfig->maxIntervals;

		HandleNextInterval();
	}
}


void UIntervalWatch::HandleNextInterval()
{
	GEngine->AddOnScreenDebugMessage(-4, 2, FColor::Blue, "Interval Index " + FString::FromInt(intervalIndex));
}

