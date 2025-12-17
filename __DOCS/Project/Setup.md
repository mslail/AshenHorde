# Project Setup

## Overview
This guide covers the initial setup steps required to configure the AshenHorde project.

## Blueprint Creation

### 1. Create Core Blueprints
Create blueprints from the following C++ classes:

- **Hero Character** - The player character class
- **Hero Controller** - The player controller class
- **Game Mode** - The game mode class

### 2. Configure Game Mode Blueprint
Once the blueprints are created, add them to the Game Mode blueprint configuration:

![Game Mode Configuration](image.png)

The Game Mode blueprint should reference:
- Default Pawn Class: Hero Character Blueprint
- Player Controller Class: Hero Controller Blueprint

## Project Settings Configuration

### Maps & Modes Settings
Configure the project's default maps and game modes in **Project Settings > Maps & Modes**:

#### Default Modes
- **Default GameMode**: `BP_AHGameMode`
  - This is the game mode blueprint created from your C++ game mode class

#### Default Maps
- **Editor Startup Map**: `PlayGround`(Only for testing)
  - The map that opens when you launch the Unreal Editor
- **Game Default Map**: `PlayGround`(Only for testing)
  - The map that loads when playing the game

#### Game Instance
- **Game Instance Class**: `GameInstance`
  - The game instance class for persistent game state

These settings are saved in `DefaultEngine.ini`.

## Additional Configuration
Additional setup steps will be documented here as the project evolves.