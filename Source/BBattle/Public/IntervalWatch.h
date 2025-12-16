// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameConfig.h"
#include "IntervalWatch.generated.h"

//UDELEGATE()
DECLARE_DELEGATE_OneParam(FOnNextInterval, int32)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BBATTLE_API UIntervalWatch : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UIntervalWatch();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability");
	TObjectPtr<UGameConfig> gameConfig;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FOnNextInterval OnNextInterval;

private:

	float intervalDuration;
	float intervalDelta;

	int32 intervalIndex;

	void HandleNextInterval();
	void ResetValue();
	void UpdateTick(float delta);
};
