// Copyright Callum Brogan

#pragma once

#include "Engine/EngineTypes.h"

namespace  AGCollision
{
	// Trace Channels (Project Settings -> Collisions -> Trace Channels)
	inline constexpr ECollisionChannel MousePick = ECC_GameTraceChannel1;
	inline constexpr TCHAR MousePickName[] = TEXT("MousePick");
}
