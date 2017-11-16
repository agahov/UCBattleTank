// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Engine.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EFiringState:uint8
{
	Reloading,	
	Aimimg,
	Locked
};

class UTankBarrel;
class UTankTurret;

//Holds barrel's properties and evevation
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UCBATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UTankBarrel * BarrelToSet);

	void SetTurretReference(UTankTurret * TurretToSet);



	

	// Called when the game starts
	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Tank")
	EFiringState FiringState = EFiringState::Reloading;	

	
private:

	UTankBarrel* Barrel = nullptr;	
	UTankTurret* Turret = nullptr;	

	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);

	
	
};
