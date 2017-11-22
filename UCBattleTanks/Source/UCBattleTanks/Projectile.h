 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


class UProjectileMovementComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;


UCLASS()
class UCBATTLETANKS_API AProjectile : public AActor
{
	GENERATED_BODY()

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LunchProjectile(float Speed);

protected:
	AProjectile();


private:
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComoponent, AActor* OtherActor, UPrimitiveComponent* OtherComoponent, 
	FVector NormalImpulse, const FHitResult& Hit);



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, Category = "Tank")
	float ProjectileDamage  = 100;


	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components" )
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* LunchBlast = nullptr;


	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent* ExplosionForce = nullptr;


	FTimerHandle TimerHandle;
	void TimerExpired();
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DestroyDelay = 10.f;
	
};
