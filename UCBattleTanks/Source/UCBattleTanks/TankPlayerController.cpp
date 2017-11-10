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


ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());

}