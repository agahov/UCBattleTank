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
class AProjectile;

//Holds barrel's properties and evevation
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UCBATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = Tank)
	void Ininitialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);


	UTankAimingComponent();


	
	void AimAt(FVector HitLocation);

	// void SetBarrelReference(UTankBarrel * BarrelToSet);

	// void SetTurretReference(UTankTurret * TurretToSet);


	UFUNCTION(BlueprintCallable, Category = Tank)
	void Fire();
	

	// Called when the game starts
	virtual void BeginPlay() override;

	EFiringState GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Tank")
	EFiringState FiringState = EFiringState::Reloading;	

	
private:

	
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;



	UPROPERTY(EditAnywhere, Category = Tank)
	float LaunchSpeed = 4000;//starting value

	UPROPERTY(EditAnywhere, Category = Tank)
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	UPROPERTY(EditAnywhere, Category = Tank)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;	
	UTankTurret* Turret = nullptr;	

	void MoveBarrelTowards(FVector AimDirectionLocal);
	void MoveTurretTowards(FVector AimDirectionLocal);

	FVector AimDirection;

	bool IsBarrelMoving();
	
};
