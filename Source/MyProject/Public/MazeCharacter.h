// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//include needed files
#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Blueprint/UserWidget.h"
#include "MazeCharacter.generated.h"
//class declaration
UCLASS()
class MYPROJECT_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMazeCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	APlayerController* _controller;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	//variable declaration
		float CurrentMoveSpeed;
	UPROPERTY(EditAnywhere)
		float BaseMoveSpeed;
	UPROPERTY(EditAnywhere)
		float rotationSpeed;
	UPROPERTY(EditAnywhere)
		UAnimSequence* _deathAnim;
	bool _isDead = false;
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* _stunSystem;
	UFUNCTION(BlueprintCallable)
		void ActivateStunParticleSystem();
private:
	//function declaration
	void MoveFB(float value);
	void MoveLR(float value);
	void Rotate(float value);
	FTimerHandle SpeedBuffTimerHandle;
	FTimerHandle GameOverScreenTimerHandle;
//Health 
public:
	UFUNCTION(BlueprintCallable)
		float GetCurrentHealth();
	virtual void Heal(float healAmount);
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float maxHealth;
	void IncreaseSpeed(float Amount, float Duration);
	void ResetSpeed(float Amount);
protected:
	float _currentHealth;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	virtual void Die();
public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _gameOverScreenTemplate;
	UUserWidget* _gameOverScreenInstance;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _victoryScreenTemplate;
	UUserWidget* _victoryScreenInstance;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _HudTemplate;
	UUserWidget* _HudInstance;
protected:
	virtual void OpenGameOverScreen();
	virtual void PauseGamePlay(bool bIsPaused);
	virtual void ShowMouseCursor();
public:
	virtual void OpenVictoryScreen();
};
