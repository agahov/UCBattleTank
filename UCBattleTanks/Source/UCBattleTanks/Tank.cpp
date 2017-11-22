// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"





// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


float ATank::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) 
{
	
	//auto Name = GetOwner()->GetName();
	int32 DamagePoints = FGenericPlatformMath::RoundToInt(Damage);
	int32 ApplyDamage = FMath::Clamp<int32>(DamagePoints,0, CurrentHealth);
	CurrentHealth -= ApplyDamage;
	if (CurrentHealth<=0)
	{
		UE_LOG(LogTemp,Warning, TEXT("Tank is Dead  ")); 
		//OnTankDead.Execute(); 
		//OnTankDead();
		OnTankDead.Broadcast();
		//OnTankDead.ExecuteIfBound();
	}
	return ApplyDamage;
}

float ATank::getHealthPercent()
{
	return (float)CurrentHealth / (float)StartingHealth;
}

