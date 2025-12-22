// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.h"
#include "AnimationComponent.h"
#include "MeleeAttackAbility.generated.h"
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BBATTLE_API UMeleeAttackAbility : public UAbilityBase
{
	GENERATED_BODY()
	
public:

	virtual void TriggerAbility(FAbilityData abilityData) override;

protected:

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "MeleeAttackTickNotify"))
	void MeleeAttackTickNotify();

	//HealthComponent enemyHealthComponent;
	UAnimationComponent* animComp;

	UPROPERTY(EditAnywhere, Category = "Ability")
	int32 damage;

	UPROPERTY(EditAnywhere, Category = "Ability")
	AnimationKey animKey;

};
