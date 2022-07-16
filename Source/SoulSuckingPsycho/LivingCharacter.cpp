// Fill out your copyright notice in the Description page of Project Settings.


#include "LivingCharacter.h"

// Sets default values
ALivingCharacter::ALivingCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALivingCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALivingCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ALivingCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

//Interface Functions---------------------------------------------------------------------------------------------------------------------------------------------------------------
void ALivingCharacter::CustomTakeDamage_Implementation(float Damage)
{
	CurrentHealth -= Damage;
}

void ALivingCharacter::WaitForStaminaRecharge_Implementation()
{
	ShouldRechargeStamina = false;
	GetWorldTimerManager().SetTimer(StamTimerHandle, this, &ALivingCharacter::SetShouldRechargeStamina_Implementation, StaminaRechargeDelay, false);
}

void ALivingCharacter::RechargeStamina_Implementation(float DeltaTime)
{
	if (!ShouldRechargeStamina) return;
	if (CurrentStamina >= MaxStamina)
	{
		CurrentStamina = MaxStamina;
		ShouldRechargeStamina = false;
		return;
	}

	CurrentStamina += StaminaPerSecond * DeltaTime;
}

void ALivingCharacter::SetShouldRechargeStamina_Implementation()
{
	GetWorldTimerManager().ClearTimer(StamTimerHandle);
	ShouldRechargeStamina = true;
}

bool ALivingCharacter::CanSpendStamina_Implementation()
{
	return (DashStamCost < CurrentStamina);
}

void ALivingCharacter::SpendStamina_Implementation(float StaminaCost)
{
	if (CurrentStamina < DashStamCost) return;
	CurrentStamina -= DashStamCost;
	WaitForStaminaRecharge_Implementation();
}

//End Interface Functions---------------------------------------------------------------------------------------------------------------------------------------------------------------
