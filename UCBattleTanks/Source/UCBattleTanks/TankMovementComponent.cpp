// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::IntendMoveForvard(float Throw)
{
    //UE_LOG(LogTemp,Warning, TEXT("Intem move forvard:  %f "), Throw);
    if (!LeftTrack || !RightTrack) {return;}

    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}


void UTankMovementComponent::IntendTurnRight(float Throw)
{
    //UE_LOG(LogTemp,Warning, TEXT("Intem move forvard:  %f "), Throw);
    if (!LeftTrack || !RightTrack) {return;}

    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
}


void UTankMovementComponent::IntendTurnLeft(float Throw)
{
    //UE_LOG(LogTemp,Warning, TEXT("Intem move forvard:  %f "), Throw);
    if (!LeftTrack || !RightTrack) {return;}

    LeftTrack->SetThrottle(-Throw);
    RightTrack->SetThrottle(Throw);
}


void UTankMovementComponent::Ininitialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    if (!LeftTrackToSet || !RightTrackToSet) {return;}

    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) 
{
    auto Name = GetOwner()->GetName();
    auto AIForwardIntention =  MoveVelocity.GetSafeNormal();
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();

    auto Cosfun = FVector::DotProduct(AIForwardIntention, TankForward);

   // UE_LOG(LogTemp, Warning, TEXT("%s  cos  %f"),*Name, Cosfun);
    IntendMoveForvard(Cosfun);

    auto CrossVector = FVector::CrossProduct(AIForwardIntention, TankForward);
    //UE_LOG(LogTemp, Warning, TEXT("%s cos %f||  z  %f"),*Name, Cosfun, CrossVector.Z);

    IntendTurnRight(CrossVector.Z);
}



