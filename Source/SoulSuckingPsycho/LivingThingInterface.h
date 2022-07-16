// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LivingThingInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class ULivingThingInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SOULSUCKINGPSYCHO_API ILivingThingInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//BlueprintNativeEvent ensures that the function can be overridden in c++ or Blueprints
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = LivingThingFunctions)
	void CustomTakeDamage(float Damage);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = LivingThingFunctions)
	void RechargeStamina(float DeltaTime);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = LivingThingFunctions)
	void WaitForStaminaRecharge();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = LivingThingFunctions)
	void SetShouldRechargeStamina();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = LivingThingFunctions)
	void SpendStamina(float StaminaCost);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = LivingThingFunctions)
	bool CanSpendStamina();
};
