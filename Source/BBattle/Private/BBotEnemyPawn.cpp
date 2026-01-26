// Fill out your copyright notice in the Description page of Project Settings.


#include "BBotEnemyPawn.h"
#include <LevelDataAsset.cpp>
#include "Subsystems/LevelSubSystem.h"

// Sets default values
ABBotEnemyPawn::ABBotEnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	intervalWatch = CreateDefaultSubobject<UIntervalWatch>(TEXT("IntervalWatch"));
}

// Called when the game starts or when spawned
void ABBotEnemyPawn::BeginPlay()
{
	Super::BeginPlay();

	healthComponent = GetComponentByClass<UHealthComponent>();

	healthComponent->OnDefeated.BindUObject(this, &ABBotEnemyPawn::HandleDefeated);
}

void ABBotEnemyPawn::HandleDefeated()
{
	UE_LOG(LogTemp, Error, TEXT("HandleDefeated"));
	Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()))->SetVisibility(false, true);
}

// Called every frame
void ABBotEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABBotEnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABBotEnemyPawn::UpdateEnemyData(FEnemyData enemyData)
{
	UEnemyAbilityComponent* enemyAbilityComp = GetComponentByClass<UEnemyAbilityComponent>();

	enemyAbilityComp->InitAbilities(enemyData);
	OnEnemyDataUpdated.Broadcast(enemyData);
}

FOnDefeated* ABBotEnemyPawn::GetOnDefeated()
{
	UE_LOG(LogTemp, Error, TEXT("RegisterDefeat"));
	return &healthComponent->OnDefeated;// .BindUObject(uobject, &ULevelSubSystem::HandleEnemyDefeated);
}

void ABBotEnemyPawn::ClearBeforeDestroy()
{
	//healthComponent->OnDefeated.Unbind();
}

