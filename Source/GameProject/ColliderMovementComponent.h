// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "ColliderMovementComponent.generated.h"

/**
 * learning exercise to gain an appreciation of what goes on behind the scenes
 * in the movement component and how movement components work
 */
UCLASS()
class GAMEPROJECT_API UColliderMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};
