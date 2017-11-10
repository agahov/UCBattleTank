// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UCBATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;	


	//start movint the barrow to cross hair
	void AimTowardsCrossHair();
	

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	
};
