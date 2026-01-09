// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityComponentBase.h"
#include "EnemyAbilityComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BBATTLE_API UEnemyAbilityComponent : public UAbilityComponentBase
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere, Category = "Ability")
	TArray<FAbilityData> abilityArr;

	virtual void BeginPlay() override;

	virtual void HandleNextInterval(int32 index) override;

};
