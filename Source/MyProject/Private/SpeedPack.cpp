// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedPack.h"
#include "MazeCharacter.h"

ASpeedPack::ASpeedPack()
{
	OnActorBeginOverlap.AddDynamic(this, &ASpeedPack::CheckActorType);
}
void ASpeedPack::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
		ApplySpeedBuff(Cast<AMazeCharacter>(OtherActor));
}

void ASpeedPack::ApplySpeedBuff(AActor* MazeCharacter)
{
    AMazeCharacter* Character = Cast<AMazeCharacter>(MazeCharacter);
    if (Character)
    {
        Character->IncreaseSpeed(SpeedAmount, SpeedDuration);
        this->Destroy(); // Destroy the health pack after applying the heal
    }
}
