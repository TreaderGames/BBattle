// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.h"
#include "Components/ShapeComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BlockAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BBATTLE_API UBlockAbility : public UAbilityBase
{
	GENERATED_BODY()
	
public: 

	virtual void TriggerAbility(FAbilityData abilityData) override;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	FName inactivePreset;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	FName activePreset;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ability")
	UStaticMeshComponent* shield;

	TInlineComponentArray<UShapeComponent*> allColliders;

	bool isShieldActive;

	void ToggleSheild(bool value);

	void InitReferences();

	UFUNCTION(BlueprintCallable)
	void SetShieldMesh(UStaticMeshComponent* mesh);

};
