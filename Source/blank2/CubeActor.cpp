// Fill out your copyright notice in the Description page of Project Settings.

#include "CubeActor.h"

// Sets default values
ACubeActor::ACubeActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VariavelFloat = 0;
	VariavelInt = 0;
	bVaariavelBool = false;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("abc"));
}

// Called when the game starts or when spawned
void ACubeActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CubeMesh->AddWorldRotation(FRotator(0.0, DeltaTime * 30.0, 0.0));
	CubeMesh->AddLocalRotation(FRotator(DeltaTime * 15.0, 0.0, 0.0));
}

bool ACubeActor::FuncaoExemplo(int32 Parametro1, float Parametro2)
{
	return false;
}