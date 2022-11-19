// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class GAMEPROJECT_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	/** Mesh for the floating platform */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Platform")
	class UStaticMeshComponent* Mesh;

	/** Start position of platform */
	UPROPERTY(EditAnywhere)
	FVector StartPoint;

	/** End position of platform */
	UPROPERTY(EditAnywhere, meta=(MakeEditWidget = "true"))
	FVector EndPoint;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Platform")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Platform")
	float InterpTime;
	
	FTimerHandle InterpTimer;
	
	/** Bool to keep track of whether Platform is interpolating or not */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Platform")
	bool bInterping;

	float Distance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Function which will be called by Timer to Toggle bIsInterping bool so that it can be used to move platform */
	void ToggleInterping();

	/** Function to swap to vectors, which will help in swapping start and end positions */
	void SwapVectors(FVector& VecOne, FVector& VecTwo);
};
