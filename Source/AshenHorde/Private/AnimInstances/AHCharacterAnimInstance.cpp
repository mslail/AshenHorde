// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimInstances/AHCharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Characters/AHCharacter.h"
#include "AHDebugHelper.h"

void UAHCharacterAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    // Don't rely on this being valid here
    Character = nullptr;
    CharacterMovementComponent = nullptr;
}

void UAHCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

    // Reacquire until we have a valid owner
    if (!Character)
    {
        APawn *PawnOwner = TryGetPawnOwner();
        if (!PawnOwner)
            return;

        Character = Cast<AAHCharacter>(PawnOwner);
        if (!Character)
        {
            return;
        }
    }
    if (!CharacterMovementComponent)
    {
        CharacterMovementComponent = Character->GetCharacterMovement();
        if (!CharacterMovementComponent)
            return;
    }

    GroundSpeed = Character->GetVelocity().Size2D();
    bHasAcceleration = CharacterMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
