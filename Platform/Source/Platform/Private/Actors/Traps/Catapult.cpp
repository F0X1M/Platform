// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Traps/Catapult.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"


ACatapult::ACatapult()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Box->SetupAttachment(Mesh);

	LandingZone = CreateDefaultSubobject<USphereComponent>(TEXT("LandingZone"));
	LandingZone->SetupAttachment(Mesh);
	LandingZone->SetSphereRadius(20.f, false);
	LandingZone->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LandingZone->bHiddenInGame = true;
	
}

void ACatapult::BeginPlay()
{
	Super::BeginPlay();
		
}

void ACatapult::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


void ACatapult::ActivateTrap(AActor* Actor)
{
	if (!Actor) return;

	if (ACharacter* Character = Cast<ACharacter>(Actor))
	{
		FVector StartLocation = Character->GetActorLocation(); 
		FVector EndLocation = LandingZone->GetComponentLocation();

		float Gravity = FMath::Abs(GetWorld()->GetGravityZ()); 

		float MaxHeight = FMath::Max(StartLocation.Z, EndLocation.Z) + LaunchHeight;
		float ApexTime = FMath::Sqrt(2 * (MaxHeight - StartLocation.Z) / Gravity);  
		float FallingTime = FMath::Sqrt(2 * (MaxHeight - EndLocation.Z) / Gravity);
		float TotalTime = ApexTime + FallingTime; 

		FVector HorizontalDisplacement = EndLocation - StartLocation; 
		HorizontalDisplacement.Z = 0.f;
		FVector HorizontalVelocity = HorizontalDisplacement / TotalTime;

		float VerticalVelocity = Gravity * ApexTime;

		FVector LaunchVelocity = HorizontalVelocity;
		LaunchVelocity.Z = VerticalVelocity;
		
		Character->LaunchCharacter(LaunchVelocity, true, true);
	}
}

