// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	SetRootComponent(BoxCollision);

	BoxCollision->SetSimulatePhysics(true);
	BoxCollision->SetMassOverrideInKg(NAME_None, 1.f, true);
	BoxCollision->SetLinearDamping(2.f);
	BoxCollision->SetEnableGravity(true);
	BoxCollision->SetCollisionObjectType(ECC_WorldStatic);
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Block);
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector direction = FVector(GetInputAxisValue("MoveHorizontal")*-1, GetInputAxisValue("MoveVertical"), 0);

	BoxCollision->AddForce(direction * Speed, "None", false);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveVertical", this, &AMyPlayer::MoveVertical);
	InputComponent->BindAxis("MoveHorizontal", this, &AMyPlayer::MoveHorizontal);
}


void AMyPlayer::MoveVertical(float amount)
{


}

void AMyPlayer::MoveHorizontal(float amount)
{


}