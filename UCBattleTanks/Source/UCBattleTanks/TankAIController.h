// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */


class UTankAimingComponent;

UCLASS()
class UCBATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	void Tick(float DeltaTime) override;
	void BeginPlay() override;


	//How close move ai  to palyer
	float AcceptanceRadius  = 900;

public:

	void AimAt(FVector HitLocation);
	
	APawn* GetPlayerTank() const;	

	UPROPERTY(BlueprintReadOnly, Category = Tank)
	UTankAimingComponent* TankAimingComponent = nullptr;

	
	
};
