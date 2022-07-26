// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnHit(
		UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		FVector NormalImpulse,
		const FHitResult& Hit
	);


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	UParticleSystemComponent* TrailParticles;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess="true"))
	class UProjectileMovementComponent* ProjectileMovementComponent;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UCameraShakeBase> HitCameraShakeClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	float Damage = 50;
};
