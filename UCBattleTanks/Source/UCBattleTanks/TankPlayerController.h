// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"



class ATank;
/**
 * 
 */
UCLASS()
class UCBATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:	
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

protected:	

		

public:

	UFUNCTION(BlueprintCallable, Category = "Tank")
	ATank* GetControlledTank() const;
	

	//start movint the barrow to cross hair
	void AimTowardsCrossHair();
	

	bool GetSightRayHitLocation(FVector& HitLocation) const;


	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const; 

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	
};
