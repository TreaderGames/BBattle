// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
//#include "Interfaces/IResetable.generated.h"
#include "IResetable.generated.h"
/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UResetable : public UInterface
{
	GENERATED_BODY()

};

class IResetable
{
	GENERATED_BODY()

public:

	//UFUNCTION(BlueprintNativeEvent)
	virtual void Reset() = 0;

};
