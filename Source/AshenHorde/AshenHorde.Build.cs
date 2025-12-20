// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class AshenHorde : ModuleRules
{
	public AshenHorde(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"GameplayTags",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"SlateCore",
			"AnimGraphRuntime"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			// keep empty unless you actually need private deps
		});

		string ThirdPersonPath = Path.Combine(ModuleDirectory, "TP_ThirdPerson");
		string AshenHordePath = Path.Combine(ModuleDirectory, "AshenHorde");

		PublicIncludePaths.AddRange(new string[]
		{
			AshenHordePath,
			ModuleDirectory,
			ThirdPersonPath,
			Path.Combine(ThirdPersonPath, "Variant_Platforming"),
			Path.Combine(ThirdPersonPath, "Variant_Platforming", "Animation"),
			Path.Combine(ThirdPersonPath, "Variant_Combat"),
			Path.Combine(ThirdPersonPath, "Variant_Combat", "AI"),
			Path.Combine(ThirdPersonPath, "Variant_Combat", "Animation"),
			Path.Combine(ThirdPersonPath, "Variant_Combat", "Gameplay"),
			Path.Combine(ThirdPersonPath, "Variant_Combat", "Interfaces"),
			Path.Combine(ThirdPersonPath, "Variant_Combat", "UI"),
			Path.Combine(ThirdPersonPath, "Variant_SideScrolling"),
			Path.Combine(ThirdPersonPath, "Variant_SideScrolling", "AI"),
			Path.Combine(ThirdPersonPath, "Variant_SideScrolling", "Gameplay"),
			Path.Combine(ThirdPersonPath, "Variant_SideScrolling", "Interfaces"),
			Path.Combine(ThirdPersonPath, "Variant_SideScrolling", "UI")
		});
	}
}
