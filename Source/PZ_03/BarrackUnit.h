// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "BarrackUnit.generated.h"

UCLASS()
class PZ_03_API ABarrackUnit : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABarrackUnit();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SetupMyPawn")
	USkeletalMeshComponent* MySkeletalMesh;

	UPROPERTY(BlueprintReadOnly, Category = "SetupMyPawn")
	UCapsuleComponent* MyPawnRoot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
