// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlatformPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"

APlatformPlayerController::APlatformPlayerController()
{
	
}

void APlatformPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(InputContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(InputContext, 0);
	}

	PlayerCharacter = GetPawn<ACharacter>();
	PlayerCharacter->JumpMaxHoldTime = 0.25f;
	PlayerCharacter->JumpMaxCount = 2;

}

void APlatformPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	
}

void APlatformPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlatformPlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlatformPlayerController::Look);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &APlatformPlayerController::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &APlatformPlayerController::StopJump);
	EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Started, this, &APlatformPlayerController::Dash);
}

void APlatformPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (PlayerCharacter)
	{
		PlayerCharacter->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		PlayerCharacter->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void APlatformPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void APlatformPlayerController::Jump(const FInputActionValue& InputActionValue)
{
	if (PlayerCharacter->CanJump())
	{
		PlayerCharacter->Jump();
	}

}

void APlatformPlayerController::StopJump()
{
	PlayerCharacter->StopJumping();
}

void APlatformPlayerController::Dash()
{
	FVector Velocity = FVector(PlayerCharacter->GetVelocity().X, PlayerCharacter->GetVelocity().Y, 0.f) * 10.f;

	PlayerCharacter->LaunchCharacter(Velocity, false, false);
}
