// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovementActorComponent.h"
#include "Components/ActorComponent.h"
#include "EnemyMoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BBATTLE_API UEnemyMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Custom Component")
	float enemySpeed;

	UPROPERTY(EditAnywhere, Category = "Custom Component")
	float maxDistFromPlayer;

	UPROPERTY(VisibleAnywhere, Category = "Custom Component");
	class UMovementActorComponent* movementComponent;

	TObjectPtr<ACharacter> playerCharacter;

	void MoveTowardsPlayer();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
