// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/AHCharacter.h"

#include "AbilitySystem/AHAbilitySystemComponent.h"
#include "AbilitySystem/AHAttributeSet.h"

// Sets default values
AAHCharacter::AAHCharacter()
{

	// Performance optimizations - see __DOCS/Project/AhCharacters.md for details
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->bReceivesDecals = false;

	AHAbilitySystemComponent = CreateDefaultSubobject<UAHAbilitySystemComponent>(TEXT("AHAbilitySystemComponent"));
	AHAttributeSet = CreateDefaultSubobject<UAHAttributeSet>(TEXT("AHAttributeSet"));
}

UAbilitySystemComponent *AAHCharacter::GetAbilitySystemComponent() const
{
	return GetAHAbilitySystemComponent();
}

void AAHCharacter::PossessedBy(AController *NewController)
{
	Super::PossessedBy(NewController);
	if (AHAbilitySystemComponent)
	{
		AHAbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}
