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

private:
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComoponent, AActor* OtherActor, UPrimitiveComponent* OtherComoponent, 
	FVector NormalImpulse, const FHitResult& Hit);


protected:
	AProjectile();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* LunchBlast = nullptr;


	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* ImpactBlast = nullptr;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LunchProjectile(float Speed);

	
	
};
