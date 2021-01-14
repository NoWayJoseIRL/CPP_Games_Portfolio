// Jose Mendoza

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class CARDESTRUCTION_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:

	void SetPlayerEnableState(bool SetPlayerEnabled);
	
};
