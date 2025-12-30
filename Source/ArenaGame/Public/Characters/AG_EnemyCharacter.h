// Copyright Callum Brogan

#pragma once

#include "CoreMinimal.h"
#include "AG_BaseCharacter.h"
#include "ArenaGame/Public/Interaction/AG_TargetInterface.h"
#include "AG_EnemyCharacter.generated.h"

UCLASS()
class ARENAGAME_API AAG_EnemyCharacter : public AAG_BaseCharacter, public IAG_TargetInterface
{
	GENERATED_BODY()

public:

	AAG_EnemyCharacter();
	
	/** Begin Target Interface*/
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
	/** End Target Interface*/

protected:
	
	virtual void BeginPlay() override;


};
