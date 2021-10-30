// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObstacle.h"

// Sets default values
AMyObstacle::AMyObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float sinValue = DeltaTime * sin(AngularFrequency * GetWorld()->GetTimeSeconds()) * Amplitude;
	FVector direction = FVector(0.f, sinValue, 0.f);
	AddActorLocalOffset(direction);
}

