// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


UTankTrack::UTankTrack()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

   OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

	
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComoponent, AActor* OtherActor, UPrimitiveComponent* OtherComoponent,
FVector NormalImpulse, const FHitResult& Hit)
{
    //UE_LOG(LogTemp,Warning, TEXT("Hit"));  
    DriveTrack();
    ApplySidewaysForce();
    CurrentThrottle = 0;
}


// void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
// {


// }

void UTankTrack::ApplySidewaysForce()
{
    auto DeltaTime = GetWorld()->GetDeltaSeconds();
    auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
    auto CorrectionAcceleration = -SlippageSpeed/DeltaTime * GetRightVector();
    auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent()); 
    auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration)/2;
    TankRoot->AddForce(CorrectionForce);

}


void UTankTrack::SetThrottle(float Throttle)
{

    CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1,1);
    //UE_LOG(LogTemp,Warning, TEXT("CurrentThrottle: %f"), CurrentThrottle);  
    
}


void UTankTrack::DriveTrack()
{
    auto Name = GetName();
    UE_LOG(LogTemp,Warning, TEXT("%s Drive  %f  "), * Name, CurrentThrottle);

    auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
   
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

    TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);
}



