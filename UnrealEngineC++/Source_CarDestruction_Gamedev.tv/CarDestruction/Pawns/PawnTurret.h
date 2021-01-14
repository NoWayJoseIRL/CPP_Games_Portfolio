// Jose Mendoza

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "PawnTurret.generated.h"

class APawnTank;
UCLASS()
class CARDESTRUCTION_API APawnTurret : public ABasePawn
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta=(AllowPrivateAccess = "true"))
	float FireRate = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta=(AllowPrivateAccess = "true"))
	float FireRange = 500.0f;

	FTimerHandle FireRateTimerHandle;
	APawnTank *PlayerPawn;

	void CheckFireCondition();
	
	float ReturnDistanceToPlayer();

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void HandleDestruction() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
