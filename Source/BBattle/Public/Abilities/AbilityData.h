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

USTRUCT(BlueprintType)
struct FAbilityData
{
	GENERATED_BODY()

//public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability");
	EAbilityType abilityType = EAbilityType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability");
	FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability");
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability");
	UTexture2D* icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability");
	int32 value;
};