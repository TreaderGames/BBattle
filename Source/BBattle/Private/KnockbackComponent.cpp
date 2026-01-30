// Fill out your copyright notice in the Description page of Project Settings.


#include "KnockbackComponent.h"

// Sets default values for this component's properties
UKnockbackComponent::UKnockbackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UKnockbackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	pawn = CastChecked<APawn>(GetOwner());
	
}


// Called every frame
void UKnockbackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (durationDelta > 0)
	{
		pawn->AddMovementInput(currDirection, currForce, true);
		durationDelta -= DeltaTime;
	}
}

void UKnockbackComponent::DoKnockBack(FVector direction, float force, float duration)
{
	currDirection = direction;
	currForce = force;
	durationDelta = duration;
}

