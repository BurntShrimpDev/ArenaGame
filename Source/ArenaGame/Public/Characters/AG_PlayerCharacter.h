// Copyright Callum Brogan

#pragma once

#include "CoreMinimal.h"
#include "AG_BaseCharacter.h"
#include "AG_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class ARENAGAME_API AAG_PlayerCharacter : public AAG_BaseCharacter
{
	GENERATED_BODY()

public:

	AAG_PlayerCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
private:
	
	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
	
	void InitAbilityActorInfo();
	
};
