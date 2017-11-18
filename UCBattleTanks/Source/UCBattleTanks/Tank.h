// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"



UCLASS()
class UCBATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()


private:	
	ATank();
		// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

















	
	
};
