// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAttackAbility.h"
#include "HealthComponent.h"

void UMeleeAttackAbility::BeginPlay()
{
	Super::BeginPlay();

	InitReferences();
}

void UMeleeAttackAbility::TriggerAbility(FAbilityData abilityData)
{
	Super::TriggerAbility(abilityData);

	if (abilityData.abilityType == abilityType) 
	{
		UE_LOG(LogTemp, Error, TEXT("TriggerAbility"));

		if (!IsValid(animComp))
		{
			animComp = GetOwner()->GetComponentByClass<UAnimationComponent>();
		}

		animComp->PlayAnimation(animKey);
	}
}

void UMeleeAttackAbility::MeleeAttackTickNotify()
{
	UE_LOG(LogTemp, Error, TEXT("MeleeAttackTickNotify 1"));
    if (!IsValid(hitStart))
    {
        UE_LOG(LogTemp, Error, TEXT("Hit start not found"));
        return;
    }
    UHealthComponent* healthComponent;

	FVector traceStart = hitStart->GetComponentLocation();
	FVector traceEnd = traceStart + owner->GetActorForwardVector() * range;

    FCollisionQueryParams queryParams;
    queryParams.AddIgnoredActor(owner); // Ignore self in trace

    FHitResult hit;
    UE_LOG(LogTemp, Error, TEXT("MeleeAttackTickNotify 3"));
    bool bHit = worldPtr->LineTraceSingleByChannel(
        hit,
        traceStart,
        traceEnd,
        ECC_Visibility,
        queryParams
    );
    UE_LOG(LogTemp, Error, TEXT("MeleeAttackTickNotify 4"));
    // Optional: Draw debug line to visualize trace
    //DrawDebugLine(worldPtr, traceStart, traceEnd, FColor::Green, false, 2.0f);
    //DrawDebugSphere(worldPtr, traceStart, 10.0f, 1, FColor::Green, false, 3.0f);

    if (bHit)
    {
        UE_LOG(LogTemp, Error, TEXT("Hit Actor: %s at Location: %s"),
            *hit.GetActor()->GetName(),
            *hit.ImpactPoint.ToString());

        healthComponent = hit.GetActor()->GetComponentByClass<UHealthComponent>();

        if (IsValid(healthComponent))
        {
            UE_LOG(LogTemp, Error, TEXT("Deal damage"));
            healthComponent->DealDamage(damage);
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("No hit detected."));
    }
}

void UMeleeAttackAbility::InitReferences()
{
	owner = GetOwner();
	worldPtr = GetWorld();
}
