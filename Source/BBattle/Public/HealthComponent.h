// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationComponent.h"
#include "NiagaraSystem.h"
#include "Interfaces/IResetable.h"
#include "HealthComponent.generated.h"

//UDELEGATE()
DECLARE_DELEGATE(FOnDefeated);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageTaken, int32, healthValue);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BBATTLE_API UHealthComponent : public UActorComponent, public IResetable
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Ability");
	int32 health;

	int32 currentHealth;

	UAnimationComponent* animationComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> niagaraHitAsset;

	TObjectPtr<UNiagaraComponent> hitVFXComponent;

	void ShowAttackVFX();


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void DealDamage(int32 damage);
	
	UFUNCTION(BlueprintCallable)
	int GetMaxHealth();

	UFUNCTION(BlueprintCallable)
	bool GetIsAlive();

	virtual void Reset() override;

	FOnDefeated OnDefeated;

	UPROPERTY(EditAnywhere, BlueprintAssignable);
	FOnDamageTaken OnDamageTaken;
};
