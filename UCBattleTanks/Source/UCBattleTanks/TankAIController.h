// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class UCBATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	void Tick(float DeltaTime) override;
	void BeginPlay() override;

public:

	
	ATank* GetControlledTank() const;	
	ATank* GetPlayerTank() const;	
	
	
};