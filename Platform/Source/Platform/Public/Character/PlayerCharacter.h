// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PLATFORM_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vitals")
	float Health;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vitals")
	float MaxHealth;

	UFUNCTION(BlueprintCallable, Category = "Vitals")
	float GetHealth() {return Health;}

	UFUNCTION(BlueprintCallable, Category = "Vitals")
	float GetMaxHealth() {return MaxHealth;}

	UFUNCTION(BlueprintCallable, Category = "Vitals")
	void ChangeHealth(float NewValue);

	UFUNCTION(BlueprintCallable, Category = "Vitals")
	void ChangeMaxHealth(float NewValue);
};
