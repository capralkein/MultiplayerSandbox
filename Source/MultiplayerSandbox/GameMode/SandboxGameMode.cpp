// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxGameMode.h"
#include "MultiplayerSandbox/Character/BaseCharacter.h"
#include "MultiplayerSandbox/PlayerController/BasePlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"


void ASandboxGameMode::PlayerEliminated(class ABaseCharacter* ElimCharacter, class ABasePlayerController* VictimController, ABasePlayerController* AttackerController)
{
	if (ElimCharacter)
	{
		ElimCharacter->Elim();
	}
}

void ASandboxGameMode::RequestRespawn(ACharacter* ElimmedCharacter, AController* ElimmedController)
{
	if (ElimmedCharacter)
	{
		ElimmedCharacter->Reset();
		ElimmedCharacter->Destroy();
	}
	if (ElimmedController)
	{
		TArray<AActor*> PlayerStarts;
		UGameplayStatics::GetAllActorsOfClass(this, APlayerStart::StaticClass(), PlayerStarts);
		int32 Selection = FMath::RandRange(0, PlayerStarts.Num() - 1);
		RestartPlayerAtPlayerStart(ElimmedController, PlayerStarts[Selection]);
	}
}
