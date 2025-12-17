// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/AHHeroCharacter.h"

#include "Camera/CameraComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AAHHeroCharacter::AAHHeroCharacter()
{

    // Don't rotate when the controller rotates. Let that just affect the camera.
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    // Configure character movement
    GetCharacterMovement()->bOrientRotationToMovement = true;
    // TODO: We should implement these, in UI or blueprint for more controller
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

    // TODO: We should implement these, in UI or blueprint for more controller
    // Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
    // instead of recompiling to adjust them
    GetCharacterMovement()->JumpZVelocity = 500.f;
    GetCharacterMovement()->AirControl = 0.35f;
    GetCharacterMovement()->MaxWalkSpeed = 500.f;
    GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
    GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

    // Create a camera boom (pulls in towards the player if there is a collision)
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    // TODO: We should implement these, in UI or blueprint for more controller

    CameraBoom->TargetArmLength = 250.0f;
    CameraBoom->SocketOffset = FVector(0.f, 65.f, 65.f);
    CameraBoom->bUsePawnControlRotation = true;

    // Create a follow camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;
}

void AAHHeroCharacter::BeginPlay()
{
    Super::BeginPlay();
}