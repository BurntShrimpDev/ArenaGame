// Copyright Callum Brogan


#include "ArenaGame/Public/Player/AG_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/SplineComponent.h"

AAG_PlayerController::AAG_PlayerController()
{
	bReplicates = true;
	
	Spline = CreateDefaultSubobject<USplineComponent>(FName("Spline"));
}

void AAG_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!IsValid(InputSubsystem)) return;
	for (UInputMappingContext* Context : InputMappingContexts)
	{
		InputSubsystem->AddMappingContext(Context, 0);
	}

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhancedInputComponent)) return;
	
	EnhancedInputComponent->BindAction(KeyboardMoveAction, ETriggerEvent::Triggered, this, &ThisClass::KeyboardMove);
}

void AAG_PlayerController::KeyboardMove(const FInputActionValue& Value)
{
	if (!IsValid(GetPawn())) return;
	const FVector2D KeyboardMovementVector = Value.Get<FVector2D>();
	
	//Find which way is forward
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	GetPawn()->AddMovementInput(ForwardDirection, KeyboardMovementVector.Y);
	GetPawn()->AddMovementInput(RightDirection, KeyboardMovementVector.X);
}
