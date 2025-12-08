# Development Environment Setup for Unreal Engine 5.7

This guide sets up your development environment for Unreal Engine 5.7 using **Visual Studio Code** as your code editor with Visual Studio's compiler and build tools running in the background.

## What You'll Install

1. **Visual Studio 2026** - Compiler, build tools, and debugger (required, runs in background)
2. **Visual Studio Code** - Your primary code editor (lightweight, fast, customizable)

## Required Components

**Visual Studio Community 2026**
- Version: November 2025 Feature Update (18.0.2)
- Edition: Community (or Professional/Enterprise)
- **Purpose:** Provides MSVC compiler, Windows SDK, and build tools only
- **Note:** You won't use Visual Studio as an IDE - it runs in the background

## Overview

This setup uses **Visual Studio Code as your primary code editor** with Visual Studio's powerful compiler and build tools running in the background.

**What gets installed:**
- **Visual Studio 2026** - MSVC compiler, Windows SDK, debugger (background only, not used as IDE)
- **Visual Studio Code** - Your code editor (lightweight, fast, customizable)

**Workloads in `.vsconfig`:**
- **Desktop development with C++** - For Unreal Engine 5.7 game development
- **.NET desktop development** - For editor tools, build automation, and Windows applications

## Quick Start

1. **Install Visual Studio 2026** (compiler & build tools)
   - Download Visual Studio Installer
   - Import the included `.vsconfig` file
   - Install (takes 15-30 minutes)
   
2. **Install Visual Studio Code** (your code editor)
   - Download from [code.visualstudio.com](https://code.visualstudio.com/)
   - Install C/C++ extensions (see below)
   
3. **Configure Unreal Engine 5.7**
   - Set VS Code as your source code editor
   - Refresh project files
   
4. **Start developing in VS Code!**

---

## Step 1: Install Visual Studio 2026 (Compiler & Build Tools)

**Use the included `.vsconfig` file for automatic setup:**

1. Download the Visual Studio Installer from [visualstudio.microsoft.com](https://visualstudio.microsoft.com/)
2. Run the installer and select **Visual Studio 2026 Community** (or your licensed edition)
3. When the installer opens, click **"More"** > **"Import configuration"**
4. Browse to and select the **`.vsconfig`** file (included in this repository)
5. Click **"Review details"** to see what will be installed
6. Click **"Install"** or **"Modify"** to apply the configuration

This installs the C++ compiler, Windows SDK, and all build tools that Unreal Engine needs.

**Note:** During installation, you may see a Windows SDK dialog asking which features to download. Keep all the pre-selected options and click "Download" - this is normal and required.

**You won't open Visual Studio** - it provides the compiler that runs when you build in Unreal Engine.

---

## Step 2: Install Visual Studio Code (Your Code Editor)

1. **Download and install VS Code** from [code.visualstudio.com](https://code.visualstudio.com/)

2. **Install required extensions** in VS Code:
   - Open VS Code
   - Go to Extensions (Ctrl+Shift+X)
   - Install these extensions:
     - **C/C++** (by Microsoft)
     - **C/C++ Extension Pack** (by Microsoft)
     - **Unreal Engine 4 Snippets** (by KishoreIthadi - works with UE5)

3. **Configure Unreal Engine 5.7:**
   - Open UE 5.7 Editor
   - Go to **Edit** → **Editor Preferences**
   - Search for **Source Code Editor**
   - Select **Visual Studio Code**
   - Click **Set as Default**
   - Right-click your `.uproject` file → **Generate Visual Studio Code project files**

### Your Workflow

✅ **Write code in VS Code** - Fast, lightweight editor  
✅ **Build in Unreal Engine** - Uses Visual Studio's compiler in background  
✅ **Debug from VS Code or UE** - Full debugging support  

**Important:** Visual Studio provides the compiler. Even though you never open it, Unreal Engine uses its MSVC compiler and Windows SDK when building your project.

---

## Manual Installation (Alternative)

If you prefer to manually select components instead of using the `.vsconfig` file:

### 1. Download Visual Studio

1. Download the Visual Studio Installer from [visualstudio.microsoft.com](https://visualstudio.microsoft.com/)
2. Choose **Visual Studio 2026 Community** (or your licensed edition)

**Remember:** You're installing this for the compiler and build tools only, not to use as an IDE.

### 2. Install Required Workloads

During installation, select the following workloads:

#### ✅ Desktop development with C++
**Required for Unreal Engine 5.7** - includes C++ compiler, build tools, debuggers, and profiling tools needed for game development.

#### ✅ .NET desktop development  
For building custom editor tools, build automation scripts, and Windows desktop applications that integrate with your UE 5.7 workflow.

### 3. Required Individual Components

Under the "Individual components" tab, ensure the following are selected:

#### C++ Development (Required for Unreal Engine 5.7)
- ✅ MSVC Build Tools for x64/x86 (Latest - v14.44)
- ✅ C++ ATL for x64/x86 (Latest MSVC)
- ✅ C++ Build Insights
- ✅ Just-In-Time debugger
- ✅ C++ profiling tools
- ✅ C++ CMake tools for Windows
- ✅ Windows 11 SDK (10.0.26100)
- ✅ Graphics debugging tools (for rendering/shader debugging)

#### .NET Development (Included in team configuration)
- ✅ .NET Framework 4.8 SDK
- ✅ .NET Core Runtime 10.0 and SDK
- ✅ F# language support
- ✅ Entity Framework

#### Testing & Quality Tools
- ✅ Test Adapter for Boost.Test
- ✅ Test Adapter for Google Test
- ✅ IntelliCode
- ✅ MSVC AddressSanitizer

#### Package Management
- ✅ vcpkg package manager

#### Source Control
- ✅ GitHub Copilot
- ✅ GitHub Copilot app modernization

### 4. Optional Components (Not Required but Available)

The following are available but not required for basic Unreal Engine development:
- C++ MFC for x64/x86 (Latest MSVC)
- Incredibuild - Build Acceleration
- C++/CLI support (Latest MSVC)
- C++ Clang tools for Windows
- Older MSVC versions (v141, v142, v143)
- Live Share

## Files Included

- **`.vsconfig`** - Visual Studio configuration file with all required components
  - Contains 53 component IDs including C++ tools, .NET tools, Windows SDK, testing frameworks, and more
  - Automatically installs both "Desktop development with C++" and ".NET desktop development" workloads
  - Includes all dependencies needed for Unreal Engine development and .NET desktop applications
- **`VS-Setup-README.md`** - This setup guide

Share both files with your team for consistent development environments.

---

## What Gets Installed

The `.vsconfig` file includes:

**C++ Development Components:**
- MSVC C++ compiler and build tools (v14.44)
- C++ ATL libraries
- CMake tools
- Graphics debugging tools
- C++ Build Insights
- AddressSanitizer (memory error detection)

**.NET Development Components:**
- .NET Framework 4.8 SDK and targeting packs
- .NET Core Runtime 10.0 and SDK
- F# language support
- Entity Framework
- ClickOnce publishing tools
- Blend for Visual Studio (UI design)
- .NET Model Builder

**Why .NET for UE 5.7?** While Unreal Engine itself uses C++, many teams use .NET for:
- Custom editor tools and plugins
- Build automation scripts
- Asset processing pipelines
- Project management tools
- Integration with external services

**Windows Platform:**
- Windows 11 SDK (10.0.26100)
- Windows Performance Toolkit
- Debugger and diagnostic tools

**Development Tools:**
- Visual Studio Core Editor
- IntelliCode (AI-assisted coding)
- GitHub Copilot
- vcpkg package manager
- Just-In-Time debugger
- NuGet package manager

**Testing & Quality:**
- Test Adapters for Boost.Test and Google Test
- Diagnostic and profiling tools

---

## Verification

### Verify Visual Studio Installation (Build Tools)

1. Open **Visual Studio Installer**
2. Click **"More"** > **"About"**
3. Confirm version: **Visual Studio Community 2026 (18.0.2)**
4. Verify both workloads are installed:
   - **Desktop development with C++**
   - **.NET desktop development**

### Verify VS Code Setup

1. Open **Visual Studio Code**
2. Check installed extensions (Ctrl+Shift+X):
   - ✅ C/C++ (Microsoft)
   - ✅ C/C++ Extension Pack (Microsoft)
   - ✅ Unreal Engine 4 Snippets
3. Open your UE 5.7 project in VS Code
4. Verify IntelliSense works (hover over UE code, see definitions)

### Verify Unreal Engine Integration

1. In UE 5.7 Editor, go to **Edit** → **Editor Preferences** → **Source Code**
2. Confirm **Source Code Editor** is set to **Visual Studio Code**
3. Right-click your `.uproject` file → verify you see **"Generate Visual Studio Code project files"**

---

## Unreal Engine 5.7 Compatibility

This Visual Studio configuration is specifically tested and configured for:
- **Unreal Engine 5.7** (Primary target)
- Unreal Engine 5.x (other versions)
- Unreal Engine 4.27+ (legacy projects)

**Important Notes for UE 5.7:**
- Visual Studio 2026 is officially supported by Unreal Engine 5.7
- Windows 11 SDK (10.0.26100) is required for latest features
- MSVC v14.44 toolchain is recommended for optimal compilation
- .NET components support custom editor tools and build automation scripts

**Note:** Always verify compatibility with Epic Games' official documentation for your specific Unreal Engine version.

## Troubleshooting

### Windows SDK Installation Dialog
If you see a "Windows Software Development Kit" dialog during installation:
- This is **normal and expected** - it's part of the Visual Studio installation
- Keep all pre-checked options (Debugging Tools, SDK for Desktop C++ apps, Performance Toolkit, etc.)
- Click **"Download"** to proceed
- The SDK version will be 10.0.26100.xxxx

### VS Code: IntelliSense Not Working
- Ensure C/C++ extension is installed and enabled
- In VS Code, press Ctrl+Shift+P → "C/C++: Edit Configurations (JSON)"
- Verify paths point to your UE installation
- Try: Right-click `.uproject` → **"Generate Visual Studio Code project files"**

### VS Code: "Cannot open source file" errors
- Regenerate project files: Right-click `.uproject` → **"Generate Visual Studio Code project files"**
- Reload VS Code window (Ctrl+Shift+P → "Developer: Reload Window")

### Issue: Unreal Engine doesn't detect Visual Studio
- Ensure the **Desktop development with C++** workload is installed
- Verify Windows SDK is installed
- Restart Visual Studio and the Epic Games Launcher

### Issue: Build failures
- Confirm MSVC Build Tools (Latest) is installed in Visual Studio Installer
- Check that the correct Windows SDK version is available
- Try regenerating Visual Studio project files from Unreal Engine
- **For VS Code users:** Build from UE Editor, not from VS Code terminal initially

### VS Code: Build button doesn't work
- Builds should be triggered from **Unreal Engine Editor**, not VS Code
- Use the **"Compile"** button in UE Editor or press **Ctrl+Alt+F11**
- VS Code is for editing only - compilation happens through UE using Visual Studio's compiler

## Additional Resources

### Visual Studio Code (Your Editor)
- [Visual Studio Code Download](https://code.visualstudio.com/)
- [Setting Up VS Code for Unreal Engine](https://docs.unrealengine.com/en-US/setting-up-visual-studio-code-for-unreal-engine/)
- [C/C++ Extension for VS Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [VS Code C++ Documentation](https://code.visualstudio.com/docs/languages/cpp)
- [VS Code Debugging Guide](https://code.visualstudio.com/docs/editor/debugging)
- [Unreal Engine Snippets Extension](https://marketplace.visualstudio.com/items?itemName=KishoreIthadi.unreal-engine-4-snippets)

### Unreal Engine 5.7 & Build Tools
- [Unreal Engine 5.7 Documentation](https://docs.unrealengine.com/)
- [Setting Up Visual Studio for Unreal Engine](https://docs.unrealengine.com/en-US/setting-up-visual-studio-for-unreal-engine/)
- [Visual Studio Documentation](https://docs.microsoft.com/en-us/visualstudio/)
- [Epic Games Developer Community](https://dev.epicgames.com/)
- [Unreal Engine C++ Programming Guide](https://docs.unrealengine.com/en-US/programming-with-cpp-in-unreal-engine/)

## Team Standards for UE 5.7 Development

- Always use **Visual Studio 2026** with the latest updates
- Use **MSVC v14.44** build tools (Latest)
- Keep Windows SDK version consistent: **10.0.26100**
- Enable **IntelliCode** for better code suggestions and UE5 API assistance
- Use **vcpkg** for third-party C++ package management when needed
- .NET development uses **.NET Framework 4.8** and **.NET Core 10.0** for editor tools
- Follow Epic's coding standards for Unreal Engine projects
- Use Git for version control (GitHub Copilot integration available)

---

**Development Environment:** Visual Studio Code + Visual Studio Build Tools  
**Target:** Unreal Engine 5.7  
**Last Updated:** December 2025  
**Visual Studio Version:** 2026 (18.0.2) - Compiler Only  
**Maintained By:** Development Team
