// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Traps/Catapult.h"

#include "Components/BoxComponent.h"


ACatapult::ACatapult()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Box->SetupAttachment(Mesh);
}

void ACatapult::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACatapult::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

