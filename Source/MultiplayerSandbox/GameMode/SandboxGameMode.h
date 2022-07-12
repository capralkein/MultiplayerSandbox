// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SandboxGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSANDBOX_API ASandboxGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	virtual void PlayerEliminated(class ABaseCharacter* ElimCharacter, class ABasePlayerController* VictimController, ABasePlayerController* AttackerController);
	virtual void RequestRespawn(ACharacter* ElimmedCharacter, AController* ElimmedController);

};
