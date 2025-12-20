// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimInstances/AHCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"

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

    const FVector Velocity = CharacterMovementComponent->Velocity;
    GroundSpeed = Velocity.Size2D();

    bIsFalling = CharacterMovementComponent->IsFalling();

    const float MinMoveThreshold = 0.01f;

    const bool bHasAcceleration =
        CharacterMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;

    bShouldMove = (GroundSpeed > MinMoveThreshold) && bHasAcceleration;

    const float DirectionRaw =
        UKismetAnimationLibrary::CalculateDirection(Velocity, Character->GetActorRotation());

    const float DirectionClamped = FMath::Clamp(DirectionRaw, -45.f, 45.f);

    Direction = CharacterMovementComponent->bOrientRotationToMovement
                    ? DirectionClamped
                    : DirectionRaw;
    bIsJumping = Velocity.Z > 100.f && bIsFalling;
}
