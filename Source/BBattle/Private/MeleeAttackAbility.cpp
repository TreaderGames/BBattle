// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAttackAbility.h"
#include "Kismet/GameplayStatics.h"
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
		//UE_LOG(LogTemp, Error, TEXT("TriggerAbility"));

		if (!IsValid(animComp))
		{
			animComp = GetOwner()->GetComponentByClass<UAnimationComponent>();
		}

        if (IsValid(animComp)) {
            animComp->PlayAnimation(animKey);
        }
	}
}

void UMeleeAttackAbility::MeleeAttackTickNotify()
{
    if (!IsValid(hitStart))
    {
        UE_LOG(LogTemp, Error, TEXT("trace Hit start not found"));
        return;
    }
    UHealthComponent* healthComponent;
    UKnockbackComponent* knockbackComponent;

	FVector traceStart = hitStart->GetComponentLocation();
	FVector traceEnd = traceStart + hitStart->GetForwardVector() * range;

    /*UE_LOG(LogTemp, Error, TEXT("trace trace trace"));
    UE_LOG(LogTemp, Error, TEXT("trace owner name %s"), *owner.GetName());
    UE_LOG(LogTemp, Error, TEXT("trace Start start %s"), *traceStart.ToString());
    UE_LOG(LogTemp, Error, TEXT("trace End end %s"), *traceEnd.ToString());
    UE_LOG(LogTemp, Error, TEXT("trace forward %s"), *hitStart->GetForwardVector().ToString());
    FRotator Rot = hitStart->GetComponentRotation();//GetOwner()->GetActorRotation();
    UE_LOG(LogTemp, Warning, TEXT("trace Rotation: %s"), *Rot.ToString());*/

    FCollisionQueryParams queryParams;
    queryParams.AddIgnoredActor(GetOwner()); // Ignore self in trace

    FHitResult hit;
    bool bHit = worldPtr->LineTraceSingleByChannel(
        hit,
        traceStart,
        traceEnd,
        ECC_Visibility,
        queryParams
    );
    // Optional: Draw debug line to visualize trace
    //DrawDebugLine(worldPtr, traceStart, traceEnd, FColor::Green, false, 2.0f);
    //DrawDebugSphere(worldPtr, traceStart, 10.0f, 1, FColor::Green, false, 3.0f);

    if (bHit)
    {
        /*UE_LOG(LogTemp, Error, TEXT("Hit Actor: %s at Location: %s"),
            *hit.GetActor()->GetName(),
            *hit.ImpactPoint.ToString());*/

        healthComponent = hit.GetActor()->GetComponentByClass<UHealthComponent>();
        knockbackComponent = hit.GetActor()->GetComponentByClass<UKnockbackComponent>();

        if (IsValid(healthComponent))
        {
            //UE_LOG(LogTemp, Error, TEXT("Deal damage"));
            healthComponent->DealDamage(damage);

            if (IsValid(knockbackComponent)) {
                knockbackComponent->DoKnockBack(hitStart->GetForwardVector(), knockbackForce, knockbackDuration);
            }

            if (IsValid(hitSFX))
            {
                UGameplayStatics::PlaySoundAtLocation(GetWorld(), hitSFX, hit.Location);
            }
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
