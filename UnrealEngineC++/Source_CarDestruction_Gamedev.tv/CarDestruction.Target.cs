// Jose Mendoza

using UnrealBuildTool;
using System.Collections.Generic;

public class CarDestructionTarget : TargetRules
{
	public CarDestructionTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "CarDestruction" } );
	}
}
