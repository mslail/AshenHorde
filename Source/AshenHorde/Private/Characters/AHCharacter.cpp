// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/AHCharacter.h"

// Sets default values
AAHCharacter::AAHCharacter()
{

	// Performance optimizations - see __DOCS/Project/AhCharacters.md for details
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->bReceivesDecals = false;
}
