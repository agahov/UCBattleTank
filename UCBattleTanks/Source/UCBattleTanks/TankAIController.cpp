// Fill out your copyright notice in the Description page of Project Settings.



#include "TankAIController.h"

#include "Tank.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    auto PlayerTank = GetPlayerTank();
    auto ControlledTank = Cast<ATank>(GetPawn());

   if (PlayerTank)
   {
       ControlledTank->AimAt(PlayerTank->GetActorLocation());
       ControlledTank->Fire();

   }
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

