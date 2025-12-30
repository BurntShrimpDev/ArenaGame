// Copyright Callum Brogan


#include "ArenaGame/Public/Characters/AG_BaseCharacter.h"


AAG_BaseCharacter::AAG_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	// Tick and refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* AAG_BaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


