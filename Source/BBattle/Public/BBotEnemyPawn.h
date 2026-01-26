// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IntervalWatch.h"
#include "GameFramework/DefaultPawn.h"
#include "EnemyAbilityComponent.h"
#include <HealthComponent.h>
#include "BBotEnemyPawn.generated.h"

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDataUpdated, FEnemyData, enemyData);

UCLASS()
class BBATTLE_API ABBotEnemyPawn : public ADefaultPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABBotEnemyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ability");
	TObjectPtr<UIntervalWatch> intervalWatch;

	TObjectPtr<UHealthComponent> healthComponent;

	UFUNCTION()
	void HandleDefeated();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void UpdateEnemyData(FEnemyData enemyData);

	FOnDefeated* GetOnDefeated();

	void ClearBeforeDestroy();

	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FOnEnemyDataUpdated OnEnemyDataUpdated;
};
