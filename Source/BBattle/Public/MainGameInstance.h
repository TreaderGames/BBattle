// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/PlayerDataSubSystem.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BBATTLE_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
protected:
	void InitSubSystems();

	UPROPERTY(EditAnywhere, Category = "Data Assets")
	TObjectPtr<UPlayerDataAsset> playerDataAsset;

public:
	UMainGameInstance();

	virtual void Init() override;
};
