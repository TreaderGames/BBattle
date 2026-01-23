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

	owningActor = GetOwner();

	gameStateSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UGameStateSubSystem>();
	gameStateSubsystem->OnGameOver.AddDynamic(this, &UIntervalWatch::HandleGameStateOver);
	gameStateSubsystem->OnGameStart.AddDynamic(this, &UIntervalWatch::HandleGameStateStart);

	ResetValue();

	canTick = true;
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

	if (IsValid(gameConfig)) {
		intervalDuration = gameConfig->defaultIntervalDuration;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Game Config not found"));
	}
}

void UIntervalWatch::UpdateTick(float delta)
{
	intervalDelta += delta;

	if (canTick && !owningActor->IsHidden() && IsValid(gameConfig) && intervalDelta >= intervalDuration)
	{
		intervalDelta = 0;
		intervalIndex = (intervalIndex + 1) % gameConfig->maxIntervals;

		HandleNextInterval();
	}
}

void UIntervalWatch::HandleGameStateOver(bool isWin)
{
	UE_LOG(LogTemp, Error, TEXT("UIntervalWatch HandleGameStateOver"));
	canTick = false;
}

void UIntervalWatch::HandleGameStateStart()
{
	canTick = true;
	intervalIndex = 0;
}


void UIntervalWatch::HandleNextInterval()
{
	GEngine->AddOnScreenDebugMessage(-4, 2, FColor::Blue, "Interval Index " + FString::FromInt(intervalIndex));

	OnNextInterval.ExecuteIfBound(intervalIndex);
}

