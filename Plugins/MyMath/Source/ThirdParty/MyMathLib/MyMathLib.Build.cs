using System;
using System.IO;
using UnrealBuildTool;

public class MyMathLib : ModuleRules
{
	public MyMathLib(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
		PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "lib", "MyMathLib.lib"));
		RuntimeDependencies.Add("$(BinaryOutputDir)/MyMathLib.dll", Path.Combine(ModuleDirectory, "lib", "MyMathLib.dll"));
	}
}