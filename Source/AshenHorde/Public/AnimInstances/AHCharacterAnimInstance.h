// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/AHAnimInstance.h"

#include "Characters/AHCharacter.h"

#include "AHCharacterAnimInstance.generated.h"

class AAHCharacter;
class UCharacterMovementComponent;
/**
 *
 */
UCLASS()
class ASHENHORDE_API UAHCharacterAnimInstance : public UAHAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	AAHCharacter *Character;
	UPROPERTY()
	UCharacterMovementComponent *CharacterMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, category = "AnimData|LocomotionData")
	bool bHasAcceleration;
};
