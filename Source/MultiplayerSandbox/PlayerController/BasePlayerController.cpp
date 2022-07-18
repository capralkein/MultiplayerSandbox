// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"
#include "MultiplayerSandbox/HUD/BaseHUD.h"
#include "MultiplayerSandbox/HUD/CharacterOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "MultiplayerSandbox/Character/BaseCharacter.h"

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = Cast<ABaseHUD>(GetHUD());
}

void ABasePlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(InPawn);
	if (BaseCharacter)
	{
		SetHUDHealth(BaseCharacter->GetHealth(), BaseCharacter->GetMaxHealth());
	}
}

void ABasePlayerController::SetHUDHealth(float Health, float MaxHealth)
{
	HUD = HUD == nullptr ? Cast<ABaseHUD>(GetHUD()) : HUD;

	bool bHUDValid = HUD && 
		HUD->CharacterOverlay && 
		HUD->CharacterOverlay->HealthBar && 
		HUD->CharacterOverlay->HealthText;
	if (bHUDValid)
	{
		const float HealthPercent = Health / MaxHealth;
		HUD->CharacterOverlay->HealthBar->SetPercent(HealthPercent);
		FString HealthText = FString::Printf(TEXT("%d/%d"), FMath::CeilToInt(Health), FMath::CeilToInt(MaxHealth));
		HUD->CharacterOverlay->HealthText->SetText(FText::FromString(HealthText));
	}
}

