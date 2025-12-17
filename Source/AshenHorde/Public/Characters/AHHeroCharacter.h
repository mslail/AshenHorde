// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AHCharacter.h"
#include "AHHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
/**
 *
 */
UCLASS()
class ASHENHORDE_API AAHHeroCharacter : public AAHCharacter
{
	GENERATED_BODY()
public:
	AAHHeroCharacter();

protected:
	virtual void BeginPlay();

private:
#pragma region Conponents
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent *CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent *FollowCamera;
#pragma endregion
};
