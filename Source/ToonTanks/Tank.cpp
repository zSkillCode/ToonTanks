// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATank::Move);
	PlayerInputComponent->BindAxis("Turn", this, &ATank::Turn);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ATank::Fire);
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerController)
	{
		FHitResult HitResult;
		PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

		RotateTurret(HitResult.ImpactPoint);
	}
}

void ATank::HandleDestruction()
{
	Super::HandleDestruction();

	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	bAlive = false;
}

APlayerController* ATank::GetPlayerController() const
{
	return PlayerController;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<APlayerController>(GetController());
}

void ATank::Fire()
{
	if (!bFireDelayActive)
	{
		Super::Fire();

		ToggleFireDelay();
		
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATank::ToggleFireDelay, FireDelay,false);
	}
}

void ATank::Move(const float Value)
{
	AddActorLocalOffset(FVector(Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this), 0, 0), true);
}

void ATank::Turn(const float Value)
{
	AddActorLocalRotation(FRotator(0, Value * TurnSpeed * UGameplayStatics::GetWorldDeltaSeconds(this), 0), true);
}

void ATank::ToggleFireDelay()
{
	bFireDelayActive = !bFireDelayActive;
}
