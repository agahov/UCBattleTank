// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    auto ControlledTank = GetPawn();
    

    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankPlayerController not processing the tank"));
    }

    
    TankAimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

    if (ensure(TankAimingComponent))
    {
        FoundAimingComponent(TankAimingComponent);

    }
    
}


void ATankPlayerController::SetPawn(APawn* InPawn)
{
    Super::SetPawn(InPawn);
    if (!InPawn) return;

    auto PossessedTank = Cast<ATank>(InPawn);

    if (!ensure(PossessedTank)){return;}
    PossessedTank->OnTankDead.AddUniqueDynamic(this, &ATankPlayerController::OnTankDeadHandler);

}


void ATankPlayerController::OnTankDeadHandler()
{
    UE_LOG(LogTemp,Warning, TEXT(".....  ON Player TANK DEAD Handler  "));  
}



void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrossHair();
}


void ATankPlayerController::AimTowardsCrossHair()
{
    
    auto ControlledTank = GetPawn();

    if (!ControlledTank){return;}
    //get world location if linetrace through crosshair
    //if it is hit the landscape 
        //tell controller tank to aim in this point
    FVector HitLocation;  
    if (GetSightRayHitLocation(HitLocation))
    {
        //UE_LOG(LogTemp, Warning, TEXT("1......Hit Location"));
       
        AimAt(HitLocation);
    }else
    {
        //UE_LOG(LogTemp, Warning, TEXT("0......UNHit Location"));
    }   

}    


void ATankPlayerController::AimAt(FVector HitLocation)
{
     TankAimingComponent->AimAt(HitLocation); 
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    HitLocation = FVector(1.0);
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);

    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
    
    FVector LookDirection;
    
   
 if (GetLookDirection(ScreenLocation, LookDirection))
    {
        return  GetLookVectorHitLocation(LookDirection, HitLocation); 
        
     }
  
    HitLocation = FVector(0);
    return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector WorldLocation;
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}



bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{

    FHitResult HitResult;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

    if (GetWorld()->LineTraceSingleByChannel(
        HitResult,
        StartLocation,
        EndLocation,
        ECollisionChannel::ECC_Visibility
        ))
    {

       HitLocation =  HitResult.Location;
       return true;

    }
  

    HitLocation = FVector(0);
    return false;


}

