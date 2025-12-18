# Unreal Engine Best Practices

## Garbage Collection and UObject References

### Why UPROPERTY() is Required

#### Character Reference Example
```cpp
UPROPERTY()
AAHCharacter *Character;
```

**Why UPROPERTY() is required:**

In Unreal Engine's garbage collection system, UObject references must be marked with `UPROPERTY()` to prevent the referenced object from being garbage collected. Without this macro:
- The garbage collector cannot track this reference
- If no other UPROPERTY references exist to the `AAHCharacter`, it may be prematurely destroyed
- This would leave a dangling pointer, causing crashes when accessed

Even if the property is not BlueprintReadWrite or Editable, the `UPROPERTY()` macro is essential for memory safety.

### UObject Pointer Best Practices

#### When to Use Different Pointer Types
- **Raw pointer with UPROPERTY()**: Default choice for UObject references
- **TWeakObjectPtr**: When the referenced object may be destroyed and you need to check validity
- **TObjectPtr**: Modern Unreal wrapper that provides type safety and better debugging (use with UPROPERTY())
- **Raw pointer without UPROPERTY()**: Only for non-UObject types or temporary references within a single function scope

#### Guidelines
- **Always use UPROPERTY()** for any UObject-derived pointer (AActor, UActorComponent, etc.)
- **Use raw pointers** for owner references that are guaranteed to outlive the object (like Character owning the mesh owning the AnimInstance)
- **Avoid TWeakObjectPtr** unless you specifically need to handle the case where the object may be destroyed
- **Never use TSharedPtr/TUniquePtr** for UObjects - these conflict with Unreal's garbage collection system

## Animation Instance Updates

### NativeThreadSafeUpdateAnimation

```cpp
void UAHCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
    // Thread-safe animation updates
}
```

**Why use NativeThreadSafeUpdateAnimation:**

- **Thread Safety**: This function runs on a worker thread, allowing animation calculations to happen in parallel with the game thread
- **Performance**: Offloads expensive animation calculations from the game thread, improving overall frame rate
- **Non-Blocking**: Game logic can continue executing while animations are being evaluated

**Important Restrictions:**
- **Read-only access**: Only access properties that won't be modified by the game thread
- **No function calls**: Cannot call most UObject functions (like GetOwner(), GetWorld(), etc.)
- **No Blueprint calls**: Cannot access Blueprint events or call Blueprint functions
- **Cache references**: Store component/actor references in NativeInitializeAnimation, not here

**Best Practice:**
- Use `NativeInitializeAnimation()` to cache actor and component references with UPROPERTY()
- Use `NativeThreadSafeUpdateAnimation()` for read-only calculations (velocity, speed, direction)
- Use `NativeUpdateAnimation()` (game thread) only when you must call functions or modify game state
