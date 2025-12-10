// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class BBATTLE_API UUtility
{
public:
	UUtility();
	~UUtility();

	static FVector2d GetMouseToRayPosition(float rayScale, UWorld* world);
};
