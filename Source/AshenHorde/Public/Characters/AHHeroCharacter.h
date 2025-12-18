// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AHCharacter.h"
#include "AHHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
struct FInputActionValue;

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
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	virtual void BeginPlay() override;

private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent *CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent *FollowCamera;
#pragma endregion

#pragma region Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig *InputConfigDataAsset;

	void Move(const FInputActionValue &Value);

	void Look(const FInputActionValue &Value);
#pragma endregion
};