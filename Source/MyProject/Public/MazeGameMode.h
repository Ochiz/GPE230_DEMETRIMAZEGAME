// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//include needed files
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/DefaultPawn.h"
#include "MazeCharacter.h"
#include "MazeGameMode.generated.h"


/**
 * 
 */
//game mode class declaration
UCLASS()
class MYPROJECT_API AMazeGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	void InitGameState() override;
private:
	//makes sure that the character spawned in is a maze character
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<AMazeCharacter> DefaultPlayerCharacter = AMazeCharacter::StaticClass();

};

