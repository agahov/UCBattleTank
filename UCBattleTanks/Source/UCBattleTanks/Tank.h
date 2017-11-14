// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;


UCLASS()
class UCBATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	

	UFUNCTION(BlueprintCallable, Category = Setup)
	void  SetBarrelReference(UTankBarrel * BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void  SetTurretReference(UTankTurret * TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void Fire();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

	// UPROPERTY(BlueprintReadOnly, Category = Tank)
	// UTankMovementComponent* TankMovementComponent = nullptr;

private:	
	ATank();
		// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Tank)
	float LaunchSpeed = 4000;//starting value

	UPROPERTY(EditAnywhere, Category = Tank)
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditAnywhere, Category = Tank)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;

	//UClass* ProjectileBlueprint;













	
	
};
