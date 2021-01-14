// Jose Mendoza

using UnrealBuildTool;
using System.Collections.Generic;

public class CarDestructionEditorTarget : TargetRules
{
	public CarDestructionEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "CarDestruction" } );
	}
}
