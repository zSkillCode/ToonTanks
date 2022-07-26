// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	virtual void HandleDestruction();

protected:
	void RotateTurret(const FVector LookAtTarget) const;

	virtual void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	class UCapsuleComponent* CapsuleComponent; // Forward declaration

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* BaseMesh; // Included by default

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	USceneComponent* ProjectileSpawnPoint;

	
	UPROPERTY(EditDefaultsOnly, Category="Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	UParticleSystem* DeathParticles;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	USoundBase* DeathSound;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UCameraShakeBase> DeathCameraShakeClass;
};
