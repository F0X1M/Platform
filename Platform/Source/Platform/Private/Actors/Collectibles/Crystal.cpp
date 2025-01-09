// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Collectibles/Crystal.h"
#include "Character/PlayerCharacter.h"


ACrystal::ACrystal()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box Component");
	BoxComponent->SetupAttachment(Mesh);
}

void ACrystal::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACrystal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACrystal::OnCollect(AActor* Collector)
{
	if (!Collector) {return;}

	if (APlayerCharacter* Character = Cast<APlayerCharacter>(Collector))
	{
		Character->Crystals++;
		this->Destroy();
	}
}

