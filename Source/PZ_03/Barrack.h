// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrackUnit.h"
#include "Particles/ParticleSystemComponent.h"
#include "Barrack.generated.h"

UCLASS()
class PZ_03_API ABarrack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrack();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* BuildingMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UClass* UnitToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpawnInterval;

	UFUNCTION()
		void SpawnUnit();

	UFUNCTION()
		void EndPlay(const EEndPlayReason::Type EndPlayReason)override;

	UPROPERTY()
		FTimerHandle SpawnTimerHandle;




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
