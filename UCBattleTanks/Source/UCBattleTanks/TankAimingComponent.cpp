// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	

	// ...
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	//UE_LOG(LogTemp,Warning, TEXT("Aim comp tick "));  

	if ((FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds)
	{
		FiringState = EFiringState::Reloading;
	}

}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
	LastFireTime = FPlatformTime::Seconds();
}


void UTankAimingComponent::Ininitialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
		Barrel = BarrelToSet;
		Turret = TurretToSet;

}




// Called every frame


void UTankAimingComponent::AimAt(FVector HitLocation)
{


	if (!Barrel) {return;}
	if (!Turret) {return;}

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	float CollisionRadius = 0;



	if (UGameplayStatics::SuggestProjectileVelocity
	(
		this,
	 	OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	)
	)
	{

		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp,Warning, TEXT("Aim at: %s "), *AimDirection.ToString());  
		MoveBarrelTowards(AimDirection);
		MoveTurretTowards(AimDirection);

	}
	else
	{
		//UE_LOG(LogTemp,Warning, TEXT("MISS.............. "));  
	}
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator  = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();


	auto DeltaRotation =  AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotation.Pitch) ; //
	

}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection)
{
	auto BarrelRotator  = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();


	auto DeltaRotation =  AimAsRotator - BarrelRotator;

	Turret->Azimuth(DeltaRotation.Yaw) ; //

}


void UTankAimingComponent::Fire()
{

 if (FiringState == EFiringState::Reloading) return;

	if (!ensure(Barrel)) {return;}
	if (!ensure(ProjectileBlueprint)){return;}

	 //bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	


	 
	 
	//if (!isReloaded){return;}
	
	LastFireTime = FPlatformTime::Seconds();

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, 
	Barrel->GetSocketLocation(FName("Projectile")),
	Barrel->GetSocketRotation(FName("Projectile")));
	
	Projectile->LunchProjectile(LaunchSpeed); 
}
