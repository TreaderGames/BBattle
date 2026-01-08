// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IntervalWatch.h"
#include "AbilityBase.h"
#include "AbilityComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BBATTLE_API UAbilityComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilityComponentBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void HandleNextInterval(int32 index);

	void InitIntervalWatch();

	TObjectPtr<UIntervalWatch> intervalWatch;

	UPROPERTY(EditAnywhere, Category = "Ability")
	TArray<TObjectPtr<UAbilityBase>> abilityBaseCollection;
		
};
