// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "LivingThingInterface.h"
#include "LivingCharacter.generated.h"

UCLASS()
class SOULSUCKINGPSYCHO_API ALivingCharacter : public ACharacter, public ILivingThingInterface
{
	GENERATED_BODY()

public:
	FTimerHandle StamTimerHandle;

	bool ShouldRechargeStamina = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LivingCharacterValues)
	float MaxHealth = 100.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = LivingCharacterValues)
	float CurrentHealth = MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LivingCharacterValues)
	float MaxStamina = 115.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = LivingCharacterValues)
	float CurrentStamina = MaxStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LivingCharacterValues)
	float StaminaRechargeDelay = 4.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LivingCharacterValues)
	float StaminaPerSecond = 50.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LivingCharacterValues)
	float DashStamCost = 25.f;

public:
	// Sets default values for this character's properties
	ALivingCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void CustomTakeDamage_Implementation(float Damage) override;
	void RechargeStamina_Implementation(float deltatime) override;
	void WaitForStaminaRecharge_Implementation() override;
	void SetShouldRechargeStamina_Implementation() override;
	void SpendStamina_Implementation(float StaminaCost) override;


};
