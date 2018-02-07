// Fill out your copyright notice in the Description page of Project Settings.

#include "BarrackUnit.h"


// Sets default values
ABarrackUnit::ABarrackUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MyPawnRoot = CreateDefaultSubobject<UCapsuleComponent>("RootCapsuleCollider");
	//MyPawnRoot->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	MyPawnRoot->InitCapsuleSize(50.f, 50.f);
	RootComponent = MyPawnRoot;

	MySkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	//MySkeletalMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	//MySkeletalMesh->SetRelativeLocationAndRotation(FVector(0.f, 0.f, .50f), FRotator(0.f, 0.f, 0.f));
	MySkeletalMesh->SetupAttachment(MyPawnRoot);
	auto LoadSkeletalMesh = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Creature_Spider/SK_EXO_Creature_Spider02.SK_EXO_Creature_Spider02'"));

	if (LoadSkeletalMesh.Object)
	{
		MySkeletalMesh->SetSkeletalMesh(LoadSkeletalMesh.Object);
	}

	auto LoadAnimInstance = ConstructorHelpers::FObjectFinder<UAnimBlueprint>(TEXT("AnimBlueprint'/Game/InfinityBladeAdversaries/Enemy/Enemy_Creature_Spider/Spider_AnimBP.Spider_AnimBP'"));
	if (LoadAnimInstance.Object)
	{
		MySkeletalMesh->SetAnimInstanceClass(LoadAnimInstance.Object->GeneratedClass);
	}

}

// Called when the game starts or when spawned
void ABarrackUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrackUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + FVector(0, 5, 0));

}

// Called to bind functionality to input
void ABarrackUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

