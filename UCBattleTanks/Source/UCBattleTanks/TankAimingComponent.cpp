// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}


void  UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void  UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{


	if (!Barrel) {return;}

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
		UE_LOG(LogTemp,Warning, TEXT("MISS.............. "));  
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

