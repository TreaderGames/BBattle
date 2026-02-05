// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/ShapeComponent.h"
#include "SlashAbility.h"
#include <Kismet/GameplayStatics.h>

void USlashAbility::TriggerAbility(FAbilityData abilityData)
{
	Super::TriggerAbility(abilityData);

	if (abilityData.abilityType == abilityType)
	{
		if (!IsValid(animComp))
		{
			animComp = GetOwner()->GetComponentByClass<UAnimationComponent>();
		}

		if (IsValid(animComp)) {
			hitCount = 0;
			healthComponents.Empty();
			animComp->PlayAnimation(animKey);
			ToggleHitCollider(true);
		}
	}
	else
	{
		ToggleHitCollider(false);
	}
}

void USlashAbility::BeginPlay()
{
	RegisterHit();
	ToggleHitCollider(false);
}

void USlashAbility::RegisterHit()
{
	TArray<UActorComponent*> actorComponentArr = GetOwner()->GetComponentsByTag(UActorComponent::StaticClass(), armColliderTag);
	UE_LOG(LogTemp, Error, TEXT("RegisterHit %s %s"), *FString::FromInt(actorComponentArr.Num()), *armColliderTag.ToString());
	for (UActorComponent* hitBox : actorComponentArr)
	{
		if (hitBox)
		{
			UShapeComponent* shapeComp = Cast<UShapeComponent>(hitBox);
			shapeComp->SetGenerateOverlapEvents(true); // Enable overlap events
			shapeComp->OnComponentBeginOverlap.AddDynamic(this, &USlashAbility::OnAttackHitBoxBeginOverlap);

			attackHitBoxes.Add(shapeComp);
			UE_LOG(LogTemp, Error, TEXT("RegisterHit 1"));
		}
	}
}

void USlashAbility::ToggleHitCollider(bool value)
{
	for (int32 i = 0; i < attackHitBoxes.Num(); i++)
	{
		if (value)
		{
			attackHitBoxes[i]->SetCollisionProfileName(FName("OverlapAll"));
		}
		else
		{
			attackHitBoxes[i]->SetCollisionProfileName(FName("NoCollision"));
		}
	}
}

void USlashAbility::OnAttackHitBoxBeginOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (otherActor != GetOwner()) {
		UHealthComponent* healthComp = otherActor->GetComponentByClass<UHealthComponent>();

		if (IsValid(healthComp))
		{
			healthComponents.AddUnique(healthComp);

			if (hitCount != healthComponents.Num())
			{
				healthComp->DealDamage(damage);
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), hitSFX, otherActor->GetActorLocation());
				hitCount = healthComponents.Num();
				UE_LOG(LogTemp, Error, TEXT("OnAttackHitBoxBeginOverlap"));
			}
		}
	}
}
