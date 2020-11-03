// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Components/ArrowComponent.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "DrawDebugHelpers.h"
#include "BaseCharacter.generated.h"

UCLASS()
class TUTPROJECT01_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float speed = 10.f;

	// Character Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Character")
		UCameraComponent* Camera; // Camera

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Character")
		USpringArmComponent *SpringArm; // Holds camera and gives collision

	UPROPERTY(EditDefaultsOnly, Category = "Base Character")
		UArrowComponent* ForwardDirection; // Forward Arrow

	UPROPERTY()
		FVector Direction;

	// Functions //

	//Movement
	void MoveForward(float amount);
	void MoveRight(float amount);
	virtual void Jump();

	//Camera
	void RotateXCamera(float amount);
	void RotateYCamera(float amount);

};
