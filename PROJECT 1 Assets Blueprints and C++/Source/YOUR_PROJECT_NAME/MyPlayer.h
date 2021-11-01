// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "MyPlayer.generated.h"

UCLASS()
class NEWPROJECT_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveVertical(float amount);
	UFUNCTION()
		void MoveHorizontal(float amount);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float Speed = -4000.f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		UBoxComponent* BoxCollision;

};
