// Jose Mendoza

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ClearBlackBoardValue.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UBTTask_ClearBlackBoardValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTTask_ClearBlackBoardValue();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
};
