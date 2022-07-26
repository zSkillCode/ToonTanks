// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;
	virtual void HandleDestruction() override;
protected:
	virtual void BeginPlay() override;
private:
	void CheckFireCondition();

	bool InFireRange() const;


	class ATank* Tank;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	float FireRange = 300;

	FTimerHandle FireRateTimerHandle;
	float FireRate = 2;
};
