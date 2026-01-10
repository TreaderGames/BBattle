// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationComponent.generated.h"


UENUM(BlueprintType)
enum class AnimationKey : uint8
{
	None,
	MeleeAttack UMETA(DisplayName = "Melee Attack"),
	Death UMETA(DisplayName = "Death"),
};

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnimationPlayed);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BBATTLE_API UAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAnimationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Ability");
	FOnAnimationPlayed OnAnimationPlayed;

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "PlayAnimation"))
	void PlayAnimation(AnimationKey key);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "GetAnimationKey"))
	AnimationKey GetAnimKey();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability");
	AnimationKey animKey;
		
};
