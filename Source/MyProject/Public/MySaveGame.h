// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		int furthestCompletedLevel;
	UPROPERTY(BlueprintReadWrite)
		float masterVolumeSetting;
	UPROPERTY(BlueprintReadWrite)
		float musicVolumeSetting;
	UPROPERTY(BlueprintReadWrite)
		float sfxVolumeSetting;

};
