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
        UE_LOG(LogTemp,Warning, TEXT("Look direction: %s"), *HitLocation.ToString());  

    }


    

}
    


bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    HitLocation = FVector(1.0);
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    // int32 CrossHairXScreenLocation = ViewportSizeX * CrossHairXLocation;
    // int32 CrossHairXScreenLocation = ViewportSizeY * CrosshairYLocation;

    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
    
    FVector LookDirection;
    //DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection);
    GetLookDirection(ScreenLocation, LookDirection);

    UE_LOG(LogTemp,Warning, TEXT("World direction: %s"), *LookDirection.ToString());  

    return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector LookDirection) const
{
    FVector WorldLocation;
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}
