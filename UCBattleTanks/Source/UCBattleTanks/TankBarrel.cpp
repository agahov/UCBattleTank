// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{

    auto Time = GetWorld()->GetTimeSeconds();
    //UE_LOG(LogTemp,Warning, TEXT("%f:: Barrel->Elevate() called"), Time);

    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
    

    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

    auto Elevation = FMath::Clamp<float>(RawNewElevation,MinElevationDegrees, MaxElevationDegrees);
    //UE_LOG(LogTemp,Warning, TEXT("%f:: Barrel->Elevate:: %f"), Time, Elevation);

    
    SetRelativeRotation(FRotator(Elevation, 0, 0));
    

}

