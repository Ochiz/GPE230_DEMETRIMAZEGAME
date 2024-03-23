// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPack.h"
#include "MazeCharacter.h"

AHealthPack::AHealthPack()
{
	OnActorBeginOverlap.AddDynamic(this, &AHealthPack::CheckActorType);
}
//check actor that overlaped for a player
void AHealthPack::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
		Apply(Cast<AMazeCharacter>(OtherActor));
}
//open the door
void AHealthPack::Apply(AActor* MazeCharacter)
{
    UGameplayStatics::PlaySound2D(this, pickupSound);
    AMazeCharacter* Character = Cast<AMazeCharacter>(MazeCharacter);
    if (Character)
    {
        Character->Heal(healAmount); 
        this->Destroy(); // Destroy the health pack after applying the heal
    }
}
