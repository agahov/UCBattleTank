// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    //ATank* ControlledTank = GetControlledTank();
    // auto ControlledTank = GetControlledTank();

    // if(!ControlledTank)
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("TankAIController not processing the tank"));
    // }
    // else
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("TankAIController  processing:  %s"), *(ControlledTank->GetName()));
    // }

    auto PlayerTank = GetPlayerTank();

    if(!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController not find the PlayerTank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController  find:  %s"), *(PlayerTank->GetName()));
    }



    
}


ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());

}


ATank* ATankAIController::GetPlayerTank() const
{
    auto TankPlayerController = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
    if (!TankPlayerController) 
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController not find the PlayerController"));
        return nullptr;
    }

    auto PlayerTank = TankPlayerController->GetControlledTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController not find the PlayerTank"));
    }

    //TankPlayerController* TankPlayerController = Cast<TankPlayerController>(GetWorld()->GetFirstPlayerController());
    return PlayerTank;

}

