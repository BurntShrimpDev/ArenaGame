// Copyright Callum Brogan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AG_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class USplineComponent;
class IAG_TargetInterface;

/**
 * 
 */
UCLASS()
class ARENAGAME_API AAG_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAG_PlayerController();
	virtual void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "Arena|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;
	
	UPROPERTY(EditDefaultsOnly, Category = "Arena|Input")
	TObjectPtr<UInputAction> KeyboardMoveAction;
	
	void KeyboardMove(const FInputActionValue& Value);
	
	FVector CachedDestination = FVector::ZeroVector;	
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;
	
	UPROPERTY(EditDefaultsOnly, Category = "Arena|Input")
	float AutoRunAcceptanceRadius = 50.f;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;
	
	void CursorTrace();
	
	TScriptInterface<IAG_TargetInterface> LastActor;
	TScriptInterface<IAG_TargetInterface> CurrentActor;
	
};
