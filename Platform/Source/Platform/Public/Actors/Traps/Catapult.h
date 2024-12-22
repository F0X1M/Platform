// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Catapult.generated.h"

class USphereComponent;

UCLASS()
class PLATFORM_API ACatapult : public AActor
{
	GENERATED_BODY()
	
public:	
	ACatapult();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent> LandingZone;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "Trap")
	void ActivateTrap(AActor* Actor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trap")
	float LaunchHeight = 0.f;

};
