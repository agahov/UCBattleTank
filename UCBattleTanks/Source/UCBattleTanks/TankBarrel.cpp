// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeDegrees)
{

    auto Time = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp,Warning, TEXT("%f:: Barrel->Elevate() called"), Time);
    

}

