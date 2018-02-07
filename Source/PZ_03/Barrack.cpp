// Fill out your copyright notice in the Description page of Project Settings.

#include "Barrack.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/CollisionProfile.h"


// Sets default values
ABarrack::ABarrack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>("BuildingMehs");
	SpawnPoint = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint");
	SpawnInterval = 5;
	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/Barrack/Warehouse_Warehouse.Warehouse_Warehouse'"));
	if (MeshAsset.Object != nullptr)
	{
		BuildingMesh->SetStaticMesh(MeshAsset.Object);
		BuildingMesh->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	}

	/*ConstructorHelpers::FObjectFinder<UParticleSystem>PSystem(TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));
	if (PSystem.Object != nullptr)
	{
		SpawnPoint->SetTemplate(PSystem.Object);
	}*/
	//SpawnPoint->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	UnitToSpawn = ABarrackUnit::StaticClass();
}

void ABarrack::SpawnUnit()
{
	FTransform SpawnLocation = SpawnPoint->GetComponentTransform();
	GetWorld()->SpawnActor<ABarrackUnit>(ABarrackUnit::StaticClass(), SpawnPoint->GetComponentTransform());
}

void ABarrack::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
}

// Called when the game starts or when spawned
void ABarrack::BeginPlay()
{
	Super::BeginPlay();
	RootComponent = BuildingMesh;
	SpawnPoint->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
	SpawnPoint->SetRelativeLocation(FVector(40, 0, 50));
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ABarrack::SpawnUnit, SpawnInterval, true);
}

// Called every frame
void ABarrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

