// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//include needed files
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "LockAndKey.generated.h"

/**
 * 
 */
//class declaration
UCLASS()
class MYPROJECT_API ALockAndKey : public ATriggerBox
{
	GENERATED_BODY()
public:
	//function declaration
	ALockAndKey();
	UFUNCTION()
		void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OpenTheDoor();
};
