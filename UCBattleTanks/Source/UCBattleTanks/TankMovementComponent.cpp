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