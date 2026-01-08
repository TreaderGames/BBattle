// Fill out your copyright notice in the Description page of Project Settings.


#include "BBotEnemyPawn.h"

// Sets default values
ABBotEnemyPawn::ABBotEnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	intervalWatch = CreateDefaultSubobject<UIntervalWatch>(TEXT("IntervalWatch"));
}

// Called when the game starts or when spawned
void ABBotEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
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

