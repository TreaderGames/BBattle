// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "BBotPlayerCharacter.h"
#include "EnemyMoveComponent.h"

// Sets default values for this component's properties
UEnemyMoveComponent::UEnemyMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	movementComponent = CreateDefaultSubobject<UMovementActorComponent>(TEXT("MovementComponent"));
}


// Called when the game starts
void UEnemyMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	UE_LOG(LogTemp, Error, TEXT("Player Name %s"), *playerCharacter->GetName());
}


void UEnemyMoveComponent::MoveTowardsPlayer()
{
	if (IsValid(movementComponent))
	{
		//UE_LOG(LogTemp, Error, TEXT("MoveTowardsPlayer %s"), *playerCharacter->GetActorLocation().ToString());
		movementComponent->MoveTowards(playerCharacter->GetActorLocation(), enemySpeed, maxDistFromPlayer);
	}
}

// Called every frame
void UEnemyMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveTowardsPlayer();
}

