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
    GetCharacterMovement()->MaxWalkSpeed = 600.f;
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