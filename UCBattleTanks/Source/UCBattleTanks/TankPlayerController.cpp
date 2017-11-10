// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    //ATank* ControlledTank = GetControlledTank();
    auto ControlledTank = GetControlledTank();

    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankPlayerController not processing the tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("TankPlayerController  processing:  %s"), *(ControlledTank->GetName()));
    }
    
}


void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //UE_LOG(LogTemp, Warning, TEXT("TankPlayerController ticking"));
    AimTowardsCrossHair();


}


ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrossHair()
{
    if (!GetControlledTank()) return;
    //get world location if linetrace through crosshair
    //if it is hit the landscape 
        //tell controller tank to aim in this point
    FVector HitLocation;  
    if (GetSightRayHitLocation(HitLocation))
    {
        UE_LOG(LogTemp,Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());  

    }


    

}
    


bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    HitLocation = FVector(1.0);
    return true;
}