// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "MovementActorComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UMovementActorComponent::UMovementActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

#pragma region Unreal

// Called when the game starts
void UMovementActorComponent::BeginPlay()
{
	Super::BeginPlay();

	pawn = CastChecked<APawn>(GetOwner());
	controller = pawn->GetController();
	healthComponent = GetOwner()->GetComponentByClass<UHealthComponent>();

	UE_LOG(LogTemp, Error, TEXT("controller %s"), *pawn->GetFName().ToString());

	if (IsValid(healthComponent)) {
		UE_LOG(LogTemp, Error, TEXT("healthComponent is valid"));
	}
}


// Called every frame
void UMovementActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
#pragma endregion

#pragma region Public

void UMovementActorComponent::Move(FVector2D inputVector)
{

	if (IsValid(controller) && IsValid(healthComponent) && healthComponent->GetIsAlive())
	{
		DoMove(inputVector);
	}
}

void UMovementActorComponent::MoveTowards(FVector inputVector, float speed, double dist)
{
	if (IsValid(healthComponent) && healthComponent->GetIsAlive())
	{
		FVector currentPos = pawn->GetActorLocation();

		if (FVector::Distance(currentPos, inputVector) >= dist) {

			FVector dirVector = inputVector - currentPos;
			FVector2D moveVector;

			dirVector.Normalize();
			//dirVector *= speed;
			moveVector = FVector2D(dirVector.Y, dirVector.X);

			LookRotate(dirVector);
			pawn->AddMovementInput(dirVector, speed);

			//UE_LOG(LogTemp, Error, TEXT("MoveTowardsPlayer %f"), FVector::Distance(currentPos, inputVector));
		}
	}
}

void UMovementActorComponent::Look(FVector2d mouseWPos)
{
	//GEngine->AddOnScreenDebugMessage(-2, 1, FColor::Blue, "UMovementActorComponent Move " + mouseWPos.ToString());
	FVector mousePosition = FVector(mouseWPos.X, mouseWPos.Y, 0);

	if (IsValid(pawn) && IsValid(healthComponent) && healthComponent->GetIsAlive())
	{
		FVector forwardDir = mousePosition - pawn->GetActorLocation();
		LookRotate(forwardDir);
	}
}
#pragma endregion


#pragma region Protected

void UMovementActorComponent::LookRotate(FVector forward)
{
	FRotator targetRotation = UKismetMathLibrary::MakeRotFromX(forward);
	targetRotation.Pitch = 0.f;
	targetRotation.Roll = 0.f;

	if (pawn)
	{
		//UE_LOG(LogTemp, Error, TEXT("LookRotate %s"), *targetRotation.ToString());
		pawn->SetActorRotation(targetRotation); //SetControlRotation(targetRotation);
	}
}

void UMovementActorComponent::DoMove(FVector2D value)
{
	//const FRotator rotation = Controller->GetControlRotation();
	//const FRotator yawRotation(0, rotation.Yaw, 0);
	//GEngine->AddOnScreenDebugMessage(-3, 1, FColor::Blue, "value " + value.ToString());
	const FVector forwardDir = FVector::ForwardVector;//FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	const FVector rightDir = FVector::RightVector;//FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

	pawn->AddMovementInput(forwardDir, value.Y);
	pawn->AddMovementInput(rightDir, value.X);
}
#pragma endregion

