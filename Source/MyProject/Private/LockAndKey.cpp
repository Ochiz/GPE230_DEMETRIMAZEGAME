// Fill out your copyright notice in the Description page of Project Settings.
//include needed files
#include "MazeCharacter.h"
#include "LockAndKey.h"
//overlap event
ALockAndKey::ALockAndKey()
{
	OnActorBeginOverlap.AddDynamic(this, &ALockAndKey::CheckActorType);
}
//check actor that overlaped for a player
void ALockAndKey::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
		OpenTheDoor();
}
//open the door
void ALockAndKey::OpenTheDoor()
{
	this->Destroy();
}