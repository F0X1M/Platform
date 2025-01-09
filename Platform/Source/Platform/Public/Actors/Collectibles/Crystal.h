// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Crystal.generated.h"

UCLASS()
class PLATFORM_API ACrystal : public AActor
{
	GENERATED_BODY()
	
public:	
	ACrystal();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> BoxComponent;
	
public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Collectible")
	void OnCollect(AActor* Collector);
};
