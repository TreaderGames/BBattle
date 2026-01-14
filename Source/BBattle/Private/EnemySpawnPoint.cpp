// Fill out your copyright notice in the Description page of Project Settings.

#include "BBotEnemyPawn.h"
#include "Kismet/GameplayStatics.h"
#include "EnemySpawnPoint.h"

// Sets default values
AEnemySpawnPoint::AEnemySpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AEnemySpawnPoint::BeginPlay()
{
	Super::BeginPlay();

    //botEnemyTemplate = UGameplayStatics::GetActorOfClass(GetWorld(), ABBotEnemyPawn::StaticClass());
	
}

void AEnemySpawnPoint::Tick(float DeltaTime)
{
}

AActor* AEnemySpawnPoint::SpawnEnemyBot(FEnemyData enemyData)
{
    if (IsValid(botEnemySubclass))
    {
        FActorSpawnParameters spawnParam;
        //spawnParam.Name = FName(TEXT("SomeNameamirite"));

        ABBotEnemyPawn* spawnedPawn = GetWorld()->SpawnActor<ABBotEnemyPawn>(botEnemySubclass, this->GetActorLocation(), FRotator::ZeroRotator, spawnParam);
        spawnedPawn->SetOwner(spawnedPawn);
        spawnedPawn->UpdateEnemyData(enemyData);

        return spawnedPawn->GetOwner();
    }

    return nullptr;
}

