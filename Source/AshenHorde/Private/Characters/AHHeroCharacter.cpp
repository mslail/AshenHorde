// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/AHHeroCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "AHGameplayTags.h"
#include "Components/Input/AHInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "AHDebugHelper.h"

AAHHeroCharacter::AAHHeroCharacter()
{

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    // Movement (free roam like Elden Ring)
    UCharacterMovementComponent *Move = GetCharacterMovement();
    Move->bOrientRotationToMovement = true;
    Move->RotationRate = FRotator(0.f, 540.f, 0.f);

    Move->MaxWalkSpeed = 480.f; // tweak
    Move->MinAnalogWalkSpeed = 20.f;
    Move->BrakingDecelerationWalking = 2048.f;
    Move->BrakingDecelerationFalling = 1500.f;

    Move->JumpZVelocity = 420.f;
    Move->AirControl = 0.25f;

    // Spring arm (centered behind character)
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);

    CameraBoom->TargetArmLength = 320.f;

    // ✅ Centered: no shoulder offset
    // Use Z only to lift camera above hips
    CameraBoom->SocketOffset = FVector(0.f, 0.f, 70.f);

    // Boom uses controller rotation => enables look up/down
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->bInheritPitch = true;
    CameraBoom->bInheritYaw = true;
    CameraBoom->bInheritRoll = false;

    // Collision + smoothing
    CameraBoom->bDoCollisionTest = true;
    CameraBoom->bEnableCameraLag = true;
    CameraBoom->CameraLagSpeed = 12.f;
    CameraBoom->bEnableCameraRotationLag = true;
    CameraBoom->CameraRotationLagSpeed = 14.f;

    // Follow camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    FollowCamera->FieldOfView = 90.f;
}

void AAHHeroCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AAHHeroCharacter::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent)
{
    checkf(InputConfigDataAsset, TEXT("Forgot to assign data asset as input config"));
    ULocalPlayer *LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
    UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
    check(Subsystem);

    Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
    UAHInputComponent *AHInputComponent = CastChecked<UAHInputComponent>(PlayerInputComponent);
    AHInputComponent->BindNativeInputComponent(InputConfigDataAsset, AHGameplayTags::InputTag_Jump, ETriggerEvent::Started, this, &ACharacter::Jump);
    AHInputComponent->BindNativeInputComponent(InputConfigDataAsset, AHGameplayTags::InputTag_Jump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
    AHInputComponent->BindNativeInputComponent(InputConfigDataAsset, AHGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Move);
    AHInputComponent->BindNativeInputComponent(InputConfigDataAsset, AHGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Look);
}

void AAHHeroCharacter::Move(const FInputActionValue &Value)
{
    // find out which way is forward
    FVector2D MovementVector = Value.Get<FVector2D>();
    const FRotator Rotation = GetController()->GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);

    if (MovementVector.Y != 0.f)
    {
        const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        // add movement
        AddMovementInput(ForwardDirection, MovementVector.Y);
    }
    if (MovementVector.X != 0.f)
    {
        const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(RightDirection, MovementVector.X);
    }
}

void AAHHeroCharacter::Look(const FInputActionValue &Value)
{
    // input is a Vector2D
    FVector2D LookAxisVector = Value.Get<FVector2D>();
    if (LookAxisVector.X != 0.f)
    {
        AddControllerYawInput(LookAxisVector.X);
    }
    if (LookAxisVector.Y != 0.f)
    {
        AddControllerPitchInput(LookAxisVector.Y);
    }
}