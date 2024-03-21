// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "SpeedPack.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API ASpeedPack : public ATriggerBox
{
	GENERATED_BODY()
public:
	ASpeedPack();
protected:
	UPROPERTY(EditAnywhere)
		float SpeedAmount;
	UPROPERTY(EditAnywhere)
		float SpeedDuration;
	UFUNCTION()
		void CheckActorType(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
		void ApplySpeedBuff(AActor* MazeCharacter);

};
