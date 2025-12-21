// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "AHCharacter.generated.h"

class UAHAbilitySystemComponent;
class UAHAttributeSet;

UCLASS()
class ASHENHORDE_API AAHCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAHCharacter();

	virtual UAbilitySystemComponent *GetAbilitySystemComponent() const;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UAHAbilitySystemComponent *AHAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UAHAttributeSet *AHAttributeSet;

	// By Pawn
	virtual void PossessedBy(AController *NewController) override;

public:
	FORCEINLINE UAHAbilitySystemComponent *GetAHAbilitySystemComponent() const
	{
		return AHAbilitySystemComponent;
	}

	FORCEINLINE UAHAttributeSet *GetAHAttributeSet() const
	{
		return AHAttributeSet;
	}
};
