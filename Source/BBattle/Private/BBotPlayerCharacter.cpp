// Fill out your copyright notice in the Description page of Project Settings.


#include "BBotPlayerCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"

// Sets default values
ABBotPlayerCharacter::ABBotPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	}

	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInputComponent->BindAction(moveIA, ETriggerEvent::Triggered, this, &ABBotPlayerCharacter::Move);
	}
}

void ABBotPlayerCharacter::Move(const FInputActionValue& value)
{
	float mouseX;
	float mouseY;
	FVector2d mousePos = GetMouseWorldPos();
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(mouseX, mouseY);

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, "Move "+ mousePos.ToString());
}

FVector2d ABBotPlayerCharacter::GetMouseWorldPos()
{
	float mouseX, mouseY;
	FVector worldLocation;
	FVector WorldDirection; 
	FVector hitLocation;

	if (APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		if (playerController->GetMousePosition(mouseX, mouseY))
		{
			// Converts the 2D mouse screen position to 3D world position and direction
			if (playerController->DeprojectMousePositionToWorld(worldLocation, WorldDirection))
			{
				FHitResult hit;
				FVector start = worldLocation;
				FVector end = start + (WorldDirection * 10000.0f); // Trace 10,000 units along direction

				if (GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Visibility))
				{
					hitLocation = hit.Location; // Actual world space position under mouse

					mouseX = hitLocation.X;
					mouseY = hitLocation.Y;
					// Use HitLocation for interactions or spawning
				}
			}
		}
	}

	FVector2d mousePos;
	mousePos.X = mouseX;
	mousePos.Y = mouseY;

	return mousePos;
}

