// Fill out your copyright notice in the Description page of Project Settings.

//include needed files
#include "MazeGameMode.h"
//initialize game state definition
void AMazeGameMode::InitGameState()
{
	Super::InitGameState();
	if (DefaultPawnClass == ADefaultPawn::StaticClass())
	{
		DefaultPawnClass = DefaultPlayerCharacter;
	}
}