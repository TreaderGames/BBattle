// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.h"
#include "KnockbackComponent.h"
#include "DashAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BBATTLE_API UDashAbility : public UAbilityBase
{
	GENERATED_BODY()
public:

	virtual void TriggerAbility(FAbilityData abilityData) override;

protected:

	virtual void BeginPlay() override;

	TObjectPtr<UKnockbackComponent> knockbackComponent;

	UPROPERTY(EditAnywhere, Category = "Ability")
	int32 knockbackForce;

	UPROPERTY(EditAnywhere, Category = "Ability")
	float knockbackDuration;

	void DoDash();
};
