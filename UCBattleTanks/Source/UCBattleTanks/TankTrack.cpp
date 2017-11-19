// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


UTankTrack::UTankTrack()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

   OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
	
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComoponent, AActor* OtherActor, UPrimitiveComponent* OtherComoponent,
FVector NormalImpulse, const FHitResult& Hit)
{
    UE_LOG(LogTemp,Warning, TEXT("Hit"));  
}


void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
  // UE_LOG(LogTemp,Warning, TEXT("Track tick "));  
    auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
    auto CorrectionAcceleration = -SlippageSpeed/DeltaTime * GetRightVector();
    auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent()); 
    auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration)/2;
    TankRoot->AddForce(CorrectionForce);

}

void UTankTrack::SetThrottle(float Throttle)
{
    
    auto Name = GetName();
    //UE_LOG(LogTemp,Warning, TEXT("%s Throttle at %f  "), * Name, Throttle);

    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
   
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

    TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);

    //UE_LOG(LogTemp,Warning, TEXT("Track RootName: %s  "), *TankRoot->GetName());
}


