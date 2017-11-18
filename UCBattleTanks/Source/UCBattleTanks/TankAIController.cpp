// Fill out your copyright notice in the Description page of Project Settings.



#include "TankAIController.h"
#include "TankPlayerController.h"
#include "TankAimingComponent.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetPawn();

    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController not processing the tank"));
    }


    TankAimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();


}


void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    auto PlayerTank = GetPlayerTank();
    auto ControlledTank = GetPawn();

   if (!ensure(PlayerTank))return;
   if (!ensure(ControlledTank)) return;

    MoveToActor(PlayerTank, AcceptanceRadius);
    AimAt(PlayerTank->GetActorLocation());
    TankAimingComponent->Fire();
}


	

void ATankAIController::AimAt(FVector HitLocation)
{
     TankAimingComponent->AimAt(HitLocation); 
}



APawn* ATankAIController::GetPlayerTank() const
{
    auto TankPlayerController = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
    if (!TankPlayerController) 
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController not find the PlayerController"));
        return nullptr;
    }

    auto PlayerTank = TankPlayerController->GetPawn();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController not find the PlayerTank"));
    }

    //TankPlayerController* TankPlayerController = Cast<TankPlayerController>(GetWorld()->GetFirstPlayerController());
    return PlayerTank;
}

