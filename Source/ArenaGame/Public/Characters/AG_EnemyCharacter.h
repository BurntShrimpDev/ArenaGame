// Copyright Callum Brogan

#pragma once

#include "CoreMinimal.h"
#include "AG_BaseCharacter.h"
#include "AG_EnemyCharacter.generated.h"

UCLASS()
class ARENAGAME_API AAG_EnemyCharacter : public AAG_BaseCharacter
{
	GENERATED_BODY()

public:

	AAG_EnemyCharacter();

protected:
	
	virtual void BeginPlay() override;


};
