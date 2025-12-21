// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AHGameplayAbility.generated.h"

UENUM(BlueprintType)

enum class EAHAbilityActionPolicy : uint8
{
	OnTriggered,
	OnGiven
};

/**
 *
 */
UCLASS()
class ASHENHORDE_API UAHGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AHAbility")
	EAHAbilityActionPolicy AbilityActionPolicy = EAHAbilityActionPolicy::OnTriggered;

	virtual void OnGiveAbility(const FGameplayAbilityActorInfo *ActorInfo, const FGameplayAbilitySpec &Spec);

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo *ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled);
};
