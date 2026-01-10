// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::DealDamage(int32 damage)
{
	if (damage > currentHealth)
	{
		currentHealth = 0;
	}
	else
	{
		currentHealth -= damage;
	}

	if (currentHealth <= 0)
	{
		if (!IsValid(animationComponent))
		{
			animationComponent = GetOwner()->GetComponentByClass<UAnimationComponent>();
		}

		animationComponent->PlayAnimation(AnimationKey::Death);
	}

	UE_LOG(LogTemp, Error, TEXT("DealDamage %d"), currentHealth);
}

