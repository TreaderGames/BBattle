#pragma once

#include "CoreMinimal.h"
#include "AbilityData.generated.h"

UENUM(BlueprintType)
enum class EAbilityType : uint8
{
	None UMETA(DisplayName = "None"),
	BasicAttack UMETA(DisplayName = "Basic Attack")
};

USTRUCT()
struct FAbilityData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Ability")
	EAbilityType abilityType = EAbilityType::None;

	UPROPERTY(EditAnywhere, Category = "Ability")
	FString description;

	UPROPERTY(EditAnywhere, Category = "Ability")
	int32 value;
};