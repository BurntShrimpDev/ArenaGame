// Copyright Callum Brogan


#include "ArenaGame/Public/Player/AG_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "ArenaGame/Public/Core/AG_Collision.h"
#include "ArenaGame/Public/Interaction/AG_TargetInterface.h"
#include "Components/SplineComponent.h"
#include "Input/AG_InputComponent.h"

AAG_PlayerController::AAG_PlayerController()
{
	bReplicates = true;

	Spline = CreateDefaultSubobject<USplineComponent>(FName("Spline"));
}

void AAG_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAG_PlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(AGCollision::MousePick, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = CurrentActor;
	CurrentActor = CursorHit.GetActor();

	if (LastActor == nullptr)
	{
		if (CurrentActor != nullptr)
		{
			CurrentActor->HighlightActor();
		}
	}
	else
	{
		if (CurrentActor == nullptr)
		{
			LastActor->UnhighlightActor();
		}
		else
		{
			if (LastActor != CurrentActor)
			{
				LastActor->UnhighlightActor();
				CurrentActor->HighlightActor();
			}
		}
	}
}

void AAG_PlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Red, *InputTag.ToString());
}

void AAG_PlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(2, 3.f, FColor::Blue, *InputTag.ToString());
}

void AAG_PlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(3, 3.f, FColor::Green, *InputTag.ToString());
}

void AAG_PlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AAG_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());
	if (!IsValid(InputSubsystem)) return;
	for (UInputMappingContext* Context : InputMappingContexts)
	{
		InputSubsystem->AddMappingContext(Context, 0);
	}

	UAG_InputComponent* AG_InputComponent = Cast<UAG_InputComponent>(InputComponent);
	if (!IsValid(AG_InputComponent)) return;

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

	AG_InputComponent->BindAction(KeyboardMoveAction, ETriggerEvent::Triggered, this, &ThisClass::KeyboardMove);	
	AG_InputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
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
