// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryTriggerVolume.h"
#include "MazeCharacter.h"

AVictoryTriggerVolume::AVictoryTriggerVolume()
{
	OnActorBeginOverlap.AddDynamic(this, &AVictoryTriggerVolume::CheckActorType);
}
//check actor that overlaped for a player
void AVictoryTriggerVolume::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
		OpenVictoryScreen(Cast<AMazeCharacter>(OtherActor));
}
//open the door
void AVictoryTriggerVolume::OpenVictoryScreen(AActor* MazeCharacter)
{
    AMazeCharacter* Character = Cast<AMazeCharacter>(MazeCharacter);
    if (Character)
    {
        Character->OpenVictoryScreen();
    }
}