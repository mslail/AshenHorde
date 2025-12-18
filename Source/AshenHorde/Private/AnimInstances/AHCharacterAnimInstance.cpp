// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimInstances/AHCharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Characters/AHCharacter.h"

void UAHCharacterAnimInstance::NativeInitializeAnimation()
{
    Character = Cast<AAHCharacter>(TryGetPawnOwner());

    if (Character)
    {
        CharacterMovementComponent = Character->GetCharacterMovement();
    }
}

void UAHCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
    if (!Character || !CharacterMovementComponent)
    {
        return;
    }

    GroundSpeed = Character->GetVelocity().Size2D();

    bHasAcceleration = CharacterMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}