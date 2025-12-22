// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAttackAbility.h"

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
	UE_LOG(LogTemp, Error, TEXT("MeleeAttackTickNotify 0"));

	FVector traceStart = skeletonComponent->GetSocketLocation(socketName);
	FVector traceEnd = traceStart + owner->GetActorForwardVector() * range;

    FCollisionQueryParams queryParams;
    queryParams.AddIgnoredActor(owner); // Ignore self in trace

    FHitResult hit;
    UE_LOG(LogTemp, Error, TEXT("MeleeAttackTickNotify 1"));
    bool bHit = worldPtr->LineTraceSingleByChannel(
        hit,
        traceStart,
        traceEnd,
        ECC_Visibility,
        queryParams
    );
    UE_LOG(LogTemp, Error, TEXT("MeleeAttackTickNotify 2"));
    // Optional: Draw debug line to visualize trace
    DrawDebugLine(worldPtr, traceStart, traceEnd, FColor::Green, false, 2.0f);

    if (bHit)
    {
        UE_LOG(LogTemp, Error, TEXT("Hit Actor: %s at Location: %s"),
            *hit.GetActor()->GetName(),
            *hit.ImpactPoint.ToString());
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
	skeletonComponent = owner->FindComponentByClass<USkeletalMeshComponent>();
}
