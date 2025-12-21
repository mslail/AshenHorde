// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AHWeaponBase.generated.h"

class USkeletalMeshComponent;
class UBoxComponent;

UCLASS()
class ASHENHORDE_API AAHWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAHWeaponBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	USkeletalMeshComponent *WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	UBoxComponent *WeaponCollisionBox;

	FORCEINLINE UBoxComponent *GetWeaponCollisionBox() const
	{
		return WeaponCollisionBox;
	}
};
