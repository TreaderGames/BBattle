// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MovementActorComponent.h"
#include "IntervalWatch.h"
#include "BBotPlayerCharacter.generated.h"


UCLASS()
class BBATTLE_API ABBotPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABBotPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = "Custom Component");
	class UMovementActorComponent* movementComponent;

protected:
	UPROPERTY(EditAnywhere, Category = "EnhancedInput");
	class UInputMappingContext* inputMapping;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput");
	class UInputAction* moveIA;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ability");
	TObjectPtr<UIntervalWatch> intervalWatch;

	void Move(const FInputActionValue& value);

	void Look();

private:
	UWorld* worldPtr;
};
