// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/AHCharacterAnimInstance.h"
#include "AHHeroAnimInstance.generated.h"

/**
 *
 */
UCLASS()
class ASHENHORDE_API UAHHeroAnimInstance : public UAHCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
};
