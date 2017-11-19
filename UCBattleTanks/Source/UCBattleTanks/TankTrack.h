// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UCBATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	public:
		UFUNCTION(BlueprintCallable, Category = Tank)
		void SetThrottle(float Throttle);

		//Max force for each track in Hewtons
		UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000 ;//assume 40 tonne tank and 1g accelleration


	private:
		UTankTrack(); 
		virtual void BeginPlay() override;
		virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

		UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComoponent, AActor* OtherActor, UPrimitiveComponent* OtherComoponent, 
		FVector NormalImpulse, const FHitResult& Hit);
	
		
		
	
};
