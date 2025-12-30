// Copyright Callum Brogan

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AG_PlayerState.generated.h"

class UAttributeSet;
class UAG_AbilitySystemComponent;
/**
 * 
 */
UCLASS()
class ARENAGAME_API AAG_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	
	AAG_PlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
protected:
	
	UPROPERTY()
	TObjectPtr<UAG_AbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
