#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EMusicType : uint8
{
    MainMenu UMETA(DisplayName = "Main Menu"),
    Ambient UMETA(DisplayName = "Ambient"),
};