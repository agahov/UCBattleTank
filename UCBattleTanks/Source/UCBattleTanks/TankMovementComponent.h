// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


class UTankTrack;
/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UCBATTLETANKS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Tank)
	void Ininitialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void IntendMoveForvard(float Throw);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void IntendTurnLeft(float Throw);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	



private:
	UTankTrack* LeftTrack = nullptr;	
	UTankTrack* RightTrack = nullptr;	
	
	
	
	
};
