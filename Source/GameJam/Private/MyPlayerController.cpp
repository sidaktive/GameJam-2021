// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "Engine/World.h"
#include "GameFramework/GameModeBase.h"

void AMyPlayerController::RequestRespawnCustom_Implementation()
{
	FOutputDeviceNull ar;
	const FString command = FString::Printf(TEXT("RespawnRequested %s"), *this->GetName());
	//const FString command = FString::Printf(TEXT("RespawnRequested"));
	AGameModeBase* gameMode = GetWorld()->GetAuthGameMode();
	if (gameMode)
	{
		gameMode->CallFunctionByNameWithArguments(*command, ar, NULL, true);
	}
}

bool AMyPlayerController::RequestRespawnCustom_Validate()
{
	return true;
}

void AMyPlayerController::BeginPlay()
{
	FOutputDeviceNull ar;
	const FString command = FString::Printf(TEXT("TeamAllocationRequested %s"), *this->GetName());
	//const FString command = FString::Printf(TEXT("RespawnRequested"));
	AGameModeBase* gameMode = GetWorld()->GetAuthGameMode();
	if (gameMode)
	{
		gameMode->CallFunctionByNameWithArguments(*command, ar, NULL, true);
	}
}
