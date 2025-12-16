// Fill out your copyright notice in the Description page of Project Settings.

#include "BBotPlayerCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "IntervalWatch.h"

//Custom
#include "UUtility.h"
#include "MovementActorComponent.h"


// Sets default values
ABBotPlayerCharacter::ABBotPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	movementComponent = CreateDefaultSubobject<UMovementActorComponent>(TEXT("MovementComponent"));
	intervalWatch = CreateDefaultSubobject<UIntervalWatch>(TEXT("IntervalWatch"));
}

// Called when the game starts or when spawned
void ABBotPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABBotPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Look();
}

// Called to bind functionality to input
void ABBotPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* playerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem <UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			subSystem->AddMappingContext(inputMapping, 0);
		}

		worldPtr = GetWorld();
	}

	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInputComponent->BindAction(moveIA, ETriggerEvent::Triggered, this, &ABBotPlayerCharacter::Move);
	}
}

void ABBotPlayerCharacter::Move(const FInputActionValue& value)
{
	if (IsValid(movementComponent))
	{
		FVector2D inputVector = value.Get<FVector2D>();
		movementComponent->Move(inputVector);
		//GEngine->AddOnScreenDebugMessage(-3, 1, FColor::Blue, "Move Move " + mousePos.ToString());
	}
	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, "Move 2"+ mousePos.ToString());
}

void ABBotPlayerCharacter::Look()
{
	FVector2d mousePos = UUtility::GetMouseToRayPosition(10000.0f, worldPtr); //GetMouseWorldPos();

	if (movementComponent != nullptr)
	{
		movementComponent->Look(mousePos);
		//GEngine->AddOnScreenDebugMessage(-3, 1, FColor::Blue, "Move Move " + mousePos.ToString());
	}
	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, "Move 2"+ mousePos.ToString());
}

