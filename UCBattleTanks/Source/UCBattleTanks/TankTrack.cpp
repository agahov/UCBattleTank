// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    
    auto Name = GetName();
    //UE_LOG(LogTemp,Warning, TEXT("%s Throttle at %f  "), * Name, Throttle);

    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
   
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

    TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);

    UE_LOG(LogTemp,Warning, TEXT("Track RootName: %s  "), *TankRoot->GetName());
}


