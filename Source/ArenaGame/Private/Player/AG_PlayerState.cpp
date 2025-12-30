// Copyright Callum Brogan


#include "ArenaGame/Public/Player/AG_PlayerState.h"

#include "AbilitySystem/AG_AbilitySystemComponent.h"
#include "AbilitySystem/AG_AttributeSet.h"

AAG_PlayerState::AAG_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAG_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UAG_AttributeSet>(TEXT("AttributeSet"));
	
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AAG_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
