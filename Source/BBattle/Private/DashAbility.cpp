// Fill out your copyright notice in the Description page of Project Settings.


#include "DashAbility.h"
#include <Kismet/GameplayStatics.h>

void UDashAbility::TriggerAbility(FAbilityData abilityData)
{
	if (abilityData.abilityType == abilityType)
	{
		DoDash();
	}
}

void UDashAbility::BeginPlay()
{
	knockbackComponent = GetOwner()->GetComponentByClass<UKnockbackComponent>();
}

void UDashAbility::DoDash()
{
	knockbackComponent->DoKnockBack(GetOwner()->GetActorForwardVector(), knockbackForce, knockbackDuration);

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), dashSFX, GetOwner()->GetActorLocation());
}
