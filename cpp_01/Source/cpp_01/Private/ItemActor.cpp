// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemActor.h"
#include "cpp_01/DebugMacros.h"

// Sets default values
// constructor
AItemActor::AItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Amplitude = 0.25f;

}

// Called when the game starts or when spawned
void AItemActor::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(FVector(0.f, 0.f, 80.f));
	SetActorRotation(FRotator(30.f, 30.f, 30.f));
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	
	// DRAW_SPHERE(Location);
	// DRAW_LINE(Location, Location + Forward * 100.f);
	// DRAW_POINT(Location + Forward * 100.f);
	// DRAW_VECTOR(Location, Location + Forward * 100.f);

	// DrawDebugSphere(World, Location, 25.f, 24, FColor::Red, false, 30.f); 
}

float AItemActor::TransformedSin()
{
	// Value = previous RunningTime
	// agora não rece mais parâmetro para usar diretamente o running time que o método já tem acesso nativo
	return Amplitude *FMath::Sin(RunningTime * TimeConstant); // period = 2*pi/K
}

float AItemActor::TransformedCos()
{
	return Amplitude *FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	// int32 AvgInt = Avg<int32>(1,3);
	// UE_LOG(LogTemp, Warning, TEXT("AvgInt: %d"), AvgInt);
	//
	// float AvgFloat = Avg<int32>(1,3);
	// UE_LOG(LogTemp, Warning, TEXT("AvgFloat: %f"), AvgFloat);


	
	// Log aparece na janela de debug padrão da unreal ou na IDE	
	UE_LOG(LogTemp, Warning, TEXT("Tick"));

	// Log aparece na tela durante o jogo
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Tick"));

	// add movimento ao actor class

	// movement rate in units of cm/s
	float MovementRate = 50.f;
	float RotationRate = 45.f;

	// MovementRate * DeltaTime (cm/s) * (s/frame) = (cm/frame)	
	// AddActorWorldOffset(FVector(1.f, 0.f, 0.f));
	// normalized vector movement
	// AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	// AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));


	/*
	**Amplitude:**
	Determina a magnitude máxima da oscilação (altura da onda)
	Se Amplitude = 5, o objeto se movimentará 5 unidades para cima e 5 unidades para baixo
	Em trigonometria, é o valor que multiplica o seno para "esticar" a onda verticalmente

	**RunningTime:**
	É um valor acumulativo de tempo que aumenta a cada frame
	Representa o parâmetro θ (theta) na fórmula do seno: sin(θ)
	À medida que o tempo avança, percorremos diferentes pontos na onda senoidal

	**TimeConstant:**
	Controla a frequência/velocidade da oscilação
	Matematicamente, é relacionado à frequência angular ω (omega)
	O comentário // period = 2*pi/K explica esta relação:
	O período (tempo para completar um ciclo) = 2π/TimeConstant
	Quanto maior o TimeConstant, menor o período e mais rápida a oscilação
	*/
	
	/*
	float DeltaZ = Amplitude *FMath::Sin(RunningTime * TimeConstant); // period = 2*pi/K
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	*/
	
	DRAW_SPHERE_SINGLE_FRAME(GetActorLocation());
	DRAW_VECTOR_SINGLE_FRAME(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	UE_LOG(LogTemp, Warning, TEXT("AvgVector: %s"), *AvgVector.ToString());
	DRAW_POINT_SINGLE_FRAME(AvgVector);
}

