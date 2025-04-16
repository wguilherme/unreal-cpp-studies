// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeActor.generated.h"

UCLASS()
class BLANK2_API ACubeActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACubeActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// guardar somente a referencia do objeto
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent *CubeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VariavelFloat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 VariavelInt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bVaariavelBool;

	UFUNCTION(BlueprintPure)
	bool FuncaoExemplo(int32 Parametro1, float Parametro2);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
};
