// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimInstances/AHCharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Characters/AHCharacter.h"
#include "AHDebugHelper.h"

void UAHCharacterAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
    Debug::Print(TEXT("INIT"));

    // Don't rely on this being valid here
    Character = nullptr;
    CharacterMovementComponent = nullptr;
}

void UAHCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    // Reacquire until we have a valid owner
    if (!Character)
    {
        APawn *PawnOwner = TryGetPawnOwner();
        if (!PawnOwner)
            return;

        Debug::Print(FString::Printf(TEXT("PawnOwner: %s (%s)"),
                                     *PawnOwner->GetName(), *PawnOwner->GetClass()->GetName()));

        Character = Cast<AAHCharacter>(PawnOwner);
        if (!Character)
        {
            Debug::Print(FString::Printf(TEXT("PawnOwner is not AAHCharacter, it's: %s"),
                                         *PawnOwner->GetClass()->GetName()));
            return;
        }
    }
    Debug::Print(TEXT("Character is present"));
    if (!CharacterMovementComponent)
    {
        CharacterMovementComponent = Character->GetCharacterMovement();
        if (!CharacterMovementComponent)
            return;
    }

    GroundSpeed = Character->GetVelocity().Size2D();
    bHasAcceleration = CharacterMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
