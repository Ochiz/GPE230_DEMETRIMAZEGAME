// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "VictoryTriggerVolume.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AVictoryTriggerVolume : public ATriggerBox
{
	GENERATED_BODY()
public:
	//function declaration
	AVictoryTriggerVolume();
	UFUNCTION()
		void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OpenVictoryScreen(AActor* MazeCharacter);
};
