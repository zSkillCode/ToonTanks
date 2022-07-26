// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* const DeadActor);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(const bool bWonGame);
private:
	void HandleGameStart();

	int32 GetTargetTowerCount() const;


	class ATank* Tank;

	class AToonTanksPlayerController* PlayerController;

	float StartDelay = 3;

	int32 TargetTowers = 0;
};
