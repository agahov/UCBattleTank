// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"



void UTankTurret::Azimuth(float RelativeSpeed)
{


    auto Time = GetWorld()->GetTimeSeconds();
    //UE_LOG(LogTemp,Warning, TEXT("%f:: Turret->Azimuth() called"), Time);

    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
    

    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;

    //auto Elevation = FMath::Clamp<float>(RawNewElevation,MinElevationDegrees, MaxElevationDegrees);
    //UE_LOG(LogTemp,Warning, TEXT("%f:: Barrel->Elevate:: %f"), Time, Elevation);

    
    SetRelativeRotation(FRotator(0, RawNewElevation, 0));
    

}
