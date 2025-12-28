// Copyright Callum Brogan

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AG_TargetInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UAG_TargetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARENAGAME_API IAG_TargetInterface
{
	GENERATED_BODY()


public:
	virtual void HighlightActor() = 0;
	virtual void UnhighlightActor() = 0;
};
