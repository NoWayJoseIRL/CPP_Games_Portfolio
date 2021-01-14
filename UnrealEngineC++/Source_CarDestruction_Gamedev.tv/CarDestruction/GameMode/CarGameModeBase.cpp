// Jose Mendoza


#include "CarGameModeBase.h"
#include "CarDestruction/Pawns/PawnTank.h"
#include "CarDestruction/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "CarDestruction/PlayerControllers/PlayerControllerBase.h"


void ACarGameModeBase::BeginPlay() 
{
    Super::BeginPlay();
    
    HandleGameStart();
}

void ACarGameModeBase::ActorDied(AActor* DeadActor)
{
    if(DeadActor == PlayerTank)
    {
        PlayerTank->HandleDestruction();
        HandleGameOver(false);

        if(PlayerControllerRef)
        {
            PlayerControllerRef->SetPlayerEnableState(false);
        }
    }
    else if(APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor))
    {
        DestroyedTurret->HandleDestruction();

        if(--TargetTurrets == 0)
        {
            HandleGameOver(true);
        }
    }
}

void ACarGameModeBase::HandleGameStart() 
{
    TargetTurrets = GetTargetTurretCount();
    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
    PlayerControllerRef = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));

    GameStart();
    if(PlayerControllerRef)
    {
        PlayerControllerRef->SetPlayerEnableState(false);

        FTimerHandle PlayerEnableHandle;
        FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(PlayerControllerRef, &APlayerControllerBase::SetPlayerEnableState, true);

        GetWorld()->GetTimerManager().SetTimer(PlayerEnableHandle, PlayerEnableDelegate, StartDelay, false);
    }
}

void ACarGameModeBase::HandleGameOver(bool PlayerWon) 
{
    GameOver(PlayerWon);
}

int32 ACarGameModeBase::GetTargetTurretCount() 
{
    TArray<AActor*> TurretActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(),TurretActors);
    return TurretActors.Num();
}
