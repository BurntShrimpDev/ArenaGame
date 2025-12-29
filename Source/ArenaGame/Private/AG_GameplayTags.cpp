// Copyright Callum Brogan


#include "ArenaGame/Public/AG_GameplayTags.h"

namespace AGTags
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(None, "AGTags.None", "None")
	namespace SetByCaller
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(SetByCaller1, "AGTags.SetByCaller.SetByCaller1", "Example Tag for SetByCaller usage.")
	}

	namespace InputTags
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(LMB, "AGTags.InputTags.LMB", "Input Tag for Left Mouse Button")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(RMB, "AGTags.InputTags.RMB", "Input Tag for Right Mouse Button")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(One, "AGTags.InputTags.One", "Input Tag for 1 Key")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Two, "AGTags.InputTags.Two", "Input Tag for 2 Key")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Three, "AGTags.InputTags.Three", "Input Tag for 3 Key")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Four, "AGTags.InputTags.Four", "Input Tag for 4 Key")
		
	}
}
