// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementActorComponent.h"

// Sets default values for this component's properties
UMovementActorComponent::UMovementActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMovementActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMovementActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMovementActorComponent::Move(FVector2d mouseWPos)
{
	GEngine->AddOnScreenDebugMessage(-2, 1, FColor::Blue, "UMovementActorComponent Move " + mouseWPos.ToString());
}

