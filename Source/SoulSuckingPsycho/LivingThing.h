// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LivingThing.generated.h"

UCLASS()
class SOULSUCKINGPSYCHO_API ALivingThing : public APawn
{
	GENERATED_BODY()
//---------------------------------------------Variables-----------------------------------------
public:

protected:
	bool ShouldRechargeStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DefaultValues)
	float MaxHealth = 100.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = DefaultValues)
	float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DefaultValues)
	float MaxStamina = 115.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = DefaultValues)
	float CurrentStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DefaultValues)
	float StaminaRechargeDelay = 4.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DefaultValues)
	float StaminaPerSecond = 50.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DefaultValues)
	float DashStamCost = 25.f;

	FTimerHandle StamTimerHandle;

private:

//---------------------------------------------Functions-----------------------------------------
public:	
	//Constructor
	ALivingThing();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void TakeDamage(float Damage);
	void RechargeStamina(float DeltaTime);
	void WaitForStaminaRecharge();
	void SetShouldRechargeStamina();
	void DecrementStamina();

private:
};
