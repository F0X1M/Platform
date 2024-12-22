// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::ChangeHealth(float Value)
{
	Health += Value;
}

void APlayerCharacter::ChangeMaxHealth(float Value)
{
	MaxHealth += Value;
}

