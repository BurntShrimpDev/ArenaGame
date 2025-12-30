// Copyright Callum Brogan


#include "ArenaGame/Public/Characters/AG_EnemyCharacter.h"

#include "AbilitySystem/AG_AbilitySystemComponent.h"
#include "AbilitySystem/AG_AttributeSet.h"
#include "ArenaGame/ArenaGame.h"


AAG_EnemyCharacter::AAG_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<UAG_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAG_AttributeSet>(TEXT("AttributeSet"));
}

void AAG_EnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAG_EnemyCharacter::UnhighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
}


void AAG_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}



