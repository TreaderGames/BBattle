// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityComponentBase.h"
#include "Subsystems/PlayerDataSubSystem.h"
#include "PlayerAbilityComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BBATTLE_API UPlayerAbilityComponent : public UAbilityComponentBase
{
	GENERATED_BODY()
	
protected:

	UPlayerDataSubSystem* playerDataSubSystem;

	virtual void HandleNextInterval(int32 index) override;

	virtual void BeginPlay() override;
};
