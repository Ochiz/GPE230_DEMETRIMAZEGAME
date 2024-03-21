// Fill out your copyright notice in the Description page of Project Settings.

//include needed files
#include "MazeCharacter.h"

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();
	_currentHealth = maxHealth;
	
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AMazeCharacter::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AMazeCharacter::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AMazeCharacter::Rotate);
}
void AMazeCharacter::ActivateStunParticleSystem()
{
	if (_stunSystem)
	{
		USceneComponent* AttachComp = GetDefaultAttachComponent();
		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(_stunSystem, AttachComp, NAME_None, FVector(0), FRotator(0), EAttachLocation::Type::KeepRelativeOffset, true);

		NiagaraComp->Activate();

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player attempted to use stun ability, but no template particle system was found"));
	}
}
//move forward/backwards definition
void AMazeCharacter::MoveFB(float value)
{
	AddMovementInput(GetActorForwardVector(), value * CurrentMoveSpeed);
}
//move left/right definition
void AMazeCharacter::MoveLR(float value)
{
	AddMovementInput(-GetActorRightVector(), value * CurrentMoveSpeed);
}
//rotate definition
void AMazeCharacter::Rotate(float value)
{
	AddControllerYawInput(value * rotationSpeed);
}

float AMazeCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	_currentHealth -= DamageAmount;
	if (!_isDead)
	{
		_currentHealth -= DamageAmount;
		if (_currentHealth <= 0)
		{
			Die();
		}
		return DamageAmount;
	}
	else
	{
		return 0;
	}
}
void AMazeCharacter::Heal(float healAmount)
{
	_currentHealth += healAmount;
	if (_currentHealth > maxHealth)
		_currentHealth = maxHealth;
}
void AMazeCharacter::Die()
{
	_isDead = true;
	_currentHealth = 0;
	CurrentMoveSpeed = 0;
	rotationSpeed = 0;

	GetMesh()->PlayAnimation(_deathAnim, false);
}
void AMazeCharacter::IncreaseSpeed(float Amount, float Duration)
{
	CurrentMoveSpeed += Amount;
	// Set a timer to reset the speed after the duration
	GetWorld()->GetTimerManager().SetTimer(SpeedBuffTimerHandle, this, &AMazeCharacter::ResetSpeed, Duration, false);
}

void AMazeCharacter::ResetSpeed()
{
	
}

