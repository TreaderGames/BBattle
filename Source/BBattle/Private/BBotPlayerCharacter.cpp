// Fill out your copyright notice in the Description page of Project Settings.


#include "BBotPlayerCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "UUtility.h"

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

		worldPtr = GetWorld();
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
	FVector2d mousePos = UUtility::GetMouseToRayPosition(1000.0f, worldPtr); //GetMouseWorldPos();
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(mouseX, mouseY);

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, "Move "+ mousePos.ToString());
}

