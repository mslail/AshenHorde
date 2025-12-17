// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EnhancedInputComponent.h"

#include "DataAssets/Input/DataAsset_InputConfig.h"

#include "AHInputComponent.generated.h"

/**
 *
 */
UCLASS()
class ASHENHORDE_API UAHInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template <class UserObject, typename CallbackFunc>
	void BindNativeInputComponent(
		const UDataAsset_InputConfig *InInputConfig,
		const FGameplayTag &InInputTag,
		ETriggerEvent TriggerEvent,
		UserObject *ContextObject,
		CallbackFunc Func);
};

template <class UserObject, typename CallbackFunc>
inline void UAHInputComponent::BindNativeInputComponent(
	const UDataAsset_InputConfig *InInputConfig,
	const FGameplayTag &InInputTag,
	ETriggerEvent TriggerEvent,
	UserObject *ContextObject,
	CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("Input config data asset is null, can not bind"));
	if (UInputAction *Action = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(Action, TriggerEvent, ContextObject, Func);
	}
}