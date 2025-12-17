# Character Documentation

## AHCharacter Configuration

### Performance Optimizations

The base character class includes several performance optimizations configured in the constructor:

#### Tick Settings
- **`PrimaryActorTick.bCanEverTick = false;`**
  - Disables the `Tick()` function for this actor
  - The actor's `Tick()` function will never be called each frame
  - Performance optimization when per-frame updates aren't needed

- **`PrimaryActorTick.bStartWithTickEnabled = false;`**
  - Ensures the tick function starts disabled when the actor spawns
  - Redundant when `bCanEverTick` is false, but useful if planning to enable ticking later via `SetActorTickEnabled()`

#### Mesh Settings
- **`GetMesh()->bReceivesDecals = false;`**
  - Prevents decals (bullet holes, blood splatter, etc.) from being projected onto the character's skeletal mesh
  - Common optimization for characters, especially in multiplayer games
  - Decals can be expensive, and players often don't notice their absence on fast-moving characters
  - Reduces CPU/GPU overhead
