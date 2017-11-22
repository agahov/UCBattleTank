// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDeadDelegate);


UCLASS()
class UCBATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

private:	
	ATank();
		// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	


public:

	FTankDeadDelegate OnTankDead;


UFUNCTION(BlueprintPure, Category="Health")
float getHealthPercent();

virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


UPROPERTY(EditAnywhere, Category = "Tank")
int32 StartingHealth = 1000;

UPROPERTY(EditAnywhere, Category = "Tank")
int32 CurrentHealth = StartingHealth;


















	
	
};
