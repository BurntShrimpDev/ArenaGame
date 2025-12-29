// Copyright Callum Brogan


#include "ArenaGame/Public/Input/AG_InputConfig.h"

const UInputAction* UAG_InputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FAG_InputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
		if (bLogNotFound)
		{
			UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction for Input Tag [%s], on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
		}
	}
	return nullptr;
}
