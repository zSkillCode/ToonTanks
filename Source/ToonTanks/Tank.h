// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;

	APlayerController* GetPlayerController() const;


	bool bAlive = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Fire() override;

private:
	void Move(const float Value);
	void Turn(const float Value);
	void ToggleFireDelay();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	class UCameraComponent* CameraComponent;


	APlayerController* PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess="true"))
	float Speed = 400;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess="true"))
	float TurnSpeed = 200;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	float FireDelay = .5;

	bool bFireDelayActive = false;
};
