// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponent.h"
#include "Abilities/AbilityData.h"
#include "Subsystems/PlayerDataSubSystem.h"
#include "Kismet/GameplayStatics.h"
#include "IntervalWatch.h"

// Sets default values for this component's properties
UAbilityComponent::UAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UAbilityComponent::DebugNotifyTick()
{
	UE_LOG(LogTemp, Error, TEXT("DebugNotifyTick"));
}


// Called when the game starts
void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	InitIntervalWatch();
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(this->GetWorld());
	playerDataSubSystem = GameInstance->GetSubsystem<UPlayerDataSubSystem>();

	GetOwner()->GetComponents<UAbilityBase>(abilityBaseCollection);

	GEngine->AddOnScreenDebugMessage(-6, 4, FColor::Blue, "abilityBaseCollection count " + FString::FromInt(abilityBaseCollection.Num()));
}

void UAbilityComponent::HandleNextInterval(int32 index)
{
	GEngine->AddOnScreenDebugMessage(-4, 2, FColor::Blue, "UAbilityComponent Interval Index " + FString::FromInt(index));
	FAbilityData abilityData = playerDataSubSystem->GetInterval(index);
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

