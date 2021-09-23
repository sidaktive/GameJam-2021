// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/OutputDeviceNull.h"
#include "GameFramework/GameMode.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
	void RequestRespawnCustom();

	UPROPERTY(EditAnywhere, Category = "GameMode Class")
	AGameMode* blueprintGameMode;

	virtual void BeginPlay() override;
};
