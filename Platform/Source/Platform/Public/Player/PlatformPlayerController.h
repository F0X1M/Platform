// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlatformPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class PLATFORM_API APlatformPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APlatformPlayerController();

	virtual void BeginPlay() override;

	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintCallable)
	void Move(const FInputActionValue& InputActionValue);

	UFUNCTION(BlueprintCallable)
	void Look(const FInputActionValue& InputActionValue);

	UFUNCTION(BlueprintCallable)
	void Jump(const FInputActionValue& InputActionValue);
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> InputContext; 

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;
	
};

