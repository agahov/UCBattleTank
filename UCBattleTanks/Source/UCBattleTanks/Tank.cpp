// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
//#include "TankMovementComponent.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponet"));
	

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


void  ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void  ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void ATank::AimAt(FVector HitLocation)
{
	 TankAimingComponent->AimAt(HitLocation, LaunchSpeed); 
}


void ATank::Fire()
{
	

	 bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	 

	if (!isReloaded){return;}
	if (!Barrel) {return;}

	LastFireTime = FPlatformTime::Seconds();


	 auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, 
	 	Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile")));

	if (!Projectile)	
	{
		UE_LOG(LogTemp,Error, TEXT("define Tank.BP_Projectile"));	
		return;
	}

	
	 Projectile->LunchProjectile(LaunchSpeed); 
}
