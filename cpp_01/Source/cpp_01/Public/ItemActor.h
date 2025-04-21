// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

UCLASS()
class CPP_01_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemActor();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Sine Parameters" )
	float TimeConstant = 5.f;

	// UFUNCTION(BlueprintCallable)
	UFUNCTION(BlueprintPure)
	float TransformedSin();

	// UFUNCTION(BlueprintCallable)
	UFUNCTION(BlueprintPure)
	float TransformedCos();

	template<typename T>
	T Avg(T First, T Second);
	

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, meta = ( AllowPrivateAccess = "true" ));
	float RunningTime;	
};

template <typename T>
inline T AItemActor::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
