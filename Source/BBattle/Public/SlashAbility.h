// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.h"
#include <AnimationComponent.h>
#include "Components/ShapeComponent.h"
#include <HealthComponent.h>
#include "SlashAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BBATTLE_API USlashAbility : public UAbilityBase
{
	GENERATED_BODY()

public:

	virtual void TriggerAbility(FAbilityData abilityData) override;

protected:

	virtual void BeginPlay() override;

	void RegisterHit();

	void ToggleHitCollider(bool value);

	FVector GetKnockBackDirectionNormalized(AActor* otherActor);

	UAnimationComponent* animComp;

	UPROPERTY(EditAnywhere, Category = "Ability")
	int32 damage;

	UPROPERTY(EditAnywhere, Category = "Ability")
	int32 knockbackForce;

	UPROPERTY(EditAnywhere, Category = "Ability")
	float knockbackDuration;

	UPROPERTY(EditAnywhere, Category = "Ability")
	AnimationKey animKey;

	UPROPERTY(EditAnywhere, Category = "Ability")
	FName armColliderTag;

	UPROPERTY(EditAnywhere, Category = "Ability")
	TObjectPtr<USoundBase> hitSFX;

	TArray<UShapeComponent*> attackHitBoxes;

	TArray<UHealthComponent*> healthComponents;

	int32 hitCount;

	UFUNCTION()
	void OnAttackHitBoxBeginOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
		UPrimitiveComponent* otherComp, int32 otherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
};
