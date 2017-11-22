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
	//bWantsBeginPlay = true; 
	PrimaryComponentTick.bCanEverTick = true;

	

	// ...
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	//UE_LOG(LogTemp,Warning, TEXT("Aim comp tick "));  

	if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
	{
		FiringState = EFiringState::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Aimimg;
	}
	else
	{
		FiringState = EFiringState::Locked;
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


	if (!ensure(Barrel)) {return;}
	if (!ensure(Turret)) {return;}

	//if (ensure(HitLocation!=NULL))return;

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

		//FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp,Warning, TEXT("Aim at: %s "), *AimDirection.ToString());  
		MoveBarrelTowards(AimDirection);
		MoveTurretTowards(AimDirection);

	}
	else
	{
		//UE_LOG(LogTemp,Warning, TEXT("MISS.............. "));  
	}
}


	EFiringState UTankAimingComponent::GetFiringState() const	
	{
		return FiringState;
	}

bool UTankAimingComponent::IsBarrelMoving()
{
	if(!ensure(Barrel)) return false;
	auto BarrelForward = Barrel->GetForwardVector();

	return !BarrelForward.Equals(AimDirection,0.01);
	
}

//TODO rename or remove AimDirection
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirectionLocal)
{
	auto BarrelRotator  = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirectionLocal.Rotation();
	//auto 
	auto DeltaRotation =  AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotation.Pitch) ; //
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirectionLocal)
{
	auto BarrelRotator  = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirectionLocal.Rotation();


	auto DeltaRotation =  AimAsRotator - BarrelRotator;

	if (FMath::Abs (DeltaRotation.Yaw) <180)
	{
		Turret->Azimuth(DeltaRotation.Yaw); 
	}else{
		Turret->Azimuth(-DeltaRotation.Yaw);
	}


	

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
