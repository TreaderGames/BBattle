// Fill out your copyright notice in the Description page of Project Settings.


#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "UUtility.h"

UUtility::UUtility()
{
}

UUtility::~UUtility()
{
}

FVector2d UUtility::GetMouseToRayPosition(float rayScale, UWorld* world)
{
	float mouseX, mouseY;
	FVector worldLocation;
	FVector WorldDirection;
	FVector hitLocation;

	if (APlayerController* playerController = UGameplayStatics::GetPlayerController(world, 0))
	{
		if (playerController->GetMousePosition(mouseX, mouseY))
		{
			// Converts the 2D mouse screen position to 3D world position and direction
			if (playerController->DeprojectMousePositionToWorld(worldLocation, WorldDirection))
			{
				FHitResult hit;
				FVector start = worldLocation;
				FVector end = start + (WorldDirection * rayScale);
				GEngine->AddOnScreenDebugMessage(-2, 1, FColor::Blue, "GetMouseToRayPosition start " + start.ToString());
				if (world->LineTraceSingleByChannel(hit, start, end, ECC_Visibility))
				{
					hitLocation = hit.Location; // Actual world space position under mouse

					mouseX = hitLocation.X;
					mouseY = hitLocation.Y;
				}
			}
		}
	}

	FVector2d mousePos;
	mousePos.X = mouseX;
	mousePos.Y = mouseY;

	return mousePos;
}
