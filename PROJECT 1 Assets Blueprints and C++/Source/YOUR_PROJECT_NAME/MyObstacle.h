// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyObstacle.generated.h"

UCLASS()
class NEWPROJECT_API AMyObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float AngularFrequency = 4.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float Amplitude = 1000.f;

};
