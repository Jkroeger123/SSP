// Fill out your copyright notice in the Description page of Project Settings.


#include "LivingThing.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ALivingThing::ALivingThing()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALivingThing::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	CurrentStamina = MaxStamina;
}

void ALivingThing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RechargeStamina(DeltaTime);
}

void ALivingThing::TakeDamage(float Damage)
{
	CurrentHealth -= Damage;
}

void ALivingThing::WaitForStaminaRecharge()
{
	ShouldRechargeStamina = false;
	GetWorldTimerManager().SetTimer(StamTimerHandle, this, &ALivingThing::SetShouldRechargeStamina, StaminaRechargeDelay, false);
}

void ALivingThing::RechargeStamina(float DeltaTime)
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

void ALivingThing::SetShouldRechargeStamina()
{
	GetWorldTimerManager().ClearTimer(StamTimerHandle);
	ShouldRechargeStamina = true;
}

void ALivingThing::DecrementStamina()
{
	if (CurrentStamina < DashStamCost) return;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::White, FString::Printf(TEXT("Begin")));
	CurrentStamina -= DashStamCost;
	WaitForStaminaRecharge();
}

// Called every frame

// Called to bind functionality to input
void ALivingThing::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
