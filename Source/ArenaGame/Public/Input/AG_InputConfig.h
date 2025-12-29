// Copyright Callum Brogan

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AG_InputConfig.generated.h"

USTRUCT(BlueprintType)
struct FAG_InputAction
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();
};

/**
 * 
 */
UCLASS()
class ARENAGAME_API UAG_InputConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false) const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FAG_InputAction> AbilityInputActions;
};
