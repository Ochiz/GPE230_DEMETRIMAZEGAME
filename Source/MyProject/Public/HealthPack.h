// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Kismet/GameplayStatics.h"
#include "HealthPack.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHealthPack : public ATriggerBox
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
		float healAmount;
	AHealthPack();
	UFUNCTION()
		void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void Apply(class AActor* AMazeCharacter);
public:
	UPROPERTY(EditAnywhere)
		USoundWave* pickupSound;
};
