// Copyright Callum Brogan

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace AGTags
{
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(None);

	namespace SetByCaller
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(SetByCaller1);
	}
	
	namespace InputTag
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(LMB);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(RMB);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(One);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Two);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Three);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Four);
	}
	
}

