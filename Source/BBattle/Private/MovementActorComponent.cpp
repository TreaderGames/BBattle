// Fill out your copyright notice in the Description page of Project Settings.


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


// Called when the game starts
void UMovementActorComponent::BeginPlay()
{
	Super::BeginPlay();

	controller = CastChecked<APawn>(GetOwner())->GetController();
}


// Called every frame
void UMovementActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMovementActorComponent::Move(FVector2d mouseWPos)
{
	GEngine->AddOnScreenDebugMessage(-2, 1, FColor::Blue, "UMovementActorComponent Move " + mouseWPos.ToString());
	FVector mousePosition = FVector(mouseWPos.X, mouseWPos.Y, 0);

	if (IsValid(controller))
	{
		FVector forwardDir = mousePosition - controller->GetPawn()->GetActorLocation();
		//forwardDir.Normalize();

		//GEngine->AddOnScreenDebugMessage(-3, 5, FColor::White, "Direction " + forwardDir.ToString());

		FRotator TargetRotation = UKismetMathLibrary::MakeRotFromX(forwardDir);
		TargetRotation.Pitch = 0.f;
		TargetRotation.Roll = 0.f;

		if (controller)
		{
			controller->SetControlRotation(TargetRotation);
		}
	}
}

