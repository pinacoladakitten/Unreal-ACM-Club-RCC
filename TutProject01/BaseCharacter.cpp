// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Spring Arm Component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));

	// Keep Spring Arm Rotation Consistent
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->SetUsingAbsoluteRotation(true);

	//Camera distance from the character
	SpringArm->TargetArmLength = 1500.f;

	// Attach Spring Arm to Character
	SpringArm->SetupAttachment(RootComponent);

	// Create Cam
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	//Change Cam FOV
	Camera->FieldOfView = 110.f;
	//Attach Cam to SpringArm
	Camera->SetupAttachment(SpringArm);

	// Create Forward Direction
	ForwardDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("Forward Direction"));
	//Set up attachment 
	ForwardDirection->SetupAttachment(RootComponent);

	// Set up character rotational movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	//Rotations Pt.2
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->RotationRate += FRotator(150.f, 150.f, 150.f);

	// Set maximum floor angle
	GetCharacterMovement()->SetWalkableFloorAngle(50.f);
	// Allow for moving up stairs
	GetCharacterMovement()->MaxStepHeight = 45.f;

	
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Bind action mappings
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ABaseCharacter::Jump);

	//Bind axis mappings
	InputComponent->BindAxis("ChangeCameraHeight", this, &ABaseCharacter::RotateYCamera);
	InputComponent->BindAxis("RotateCamera", this, &ABaseCharacter::RotateXCamera);
	InputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);
}

void ABaseCharacter::MoveForward(float amount)
{
	// Set Direction
	Direction = SpringArm->GetForwardVector() + SpringArm->GetUpVector();

	// Check controller is valid and amount != 0
	if (Controller && amount) {
		AddMovementInput(Direction, amount); // forward direction
	}
}

void ABaseCharacter::MoveRight(float amount)
{
	// Set Direction
	Direction = SpringArm->GetRightVector();

	// Check controller is valid and amount != 0
	if (Controller && amount) {
		AddMovementInput(Direction, amount); // right direction
	}
}

void ABaseCharacter::Jump() {
	Super::Jump();
}

void ABaseCharacter::RotateXCamera(float amount)
{
	// Check controller is valid and amount != 0
	if (Controller && amount) {
		FVector rot = SpringArm->GetComponentRotation().Euler();

		// Add amount
		rot += FVector(0, 0, amount*1.05f);

		//Apply the new rotation to spring arm
		SpringArm->SetWorldRotation(FQuat::MakeFromEuler(rot));
	}
}

void ABaseCharacter::RotateYCamera(float amount)
{
	// Check controller is valid and amount != 0
	if (Controller && amount) {
		FVector rot = SpringArm->GetComponentRotation().Euler();

		// Add amount
		//Separate our y rot
		float newHeight = rot.Y;
		//Add our desired rot
		newHeight += amount * 1.05f;
		//clamp the height
		newHeight = FMath::Clamp(newHeight, -80.f, 10.f);

		// build our rotation vector
		rot = FVector(0, newHeight, rot.Z);


		//Apply the new rotation to spring arm
		SpringArm->SetWorldRotation(FQuat::MakeFromEuler(rot));
	}
}
