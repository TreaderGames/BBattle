#pragma once

#include "Engine/Texture2D.h"
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
	FString name;

	UPROPERTY(EditAnywhere, Category = "Ability")
	UTexture2D* icon;

	UPROPERTY(EditAnywhere, Category = "Ability")
	int32 value;
};