// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    Isograms = GetValidWords(Words);

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else     // else Checking PlayerGuess
    {
        ProcessGuess(PlayerInput);
    }   
}
void UBullCowCartridge::SetupGame()
{
    //Welcome the player
    PrintLine (TEXT("Welcome to BullCows, we'll have some fun!"));

    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
    Lives = HiddenWord.Len() * 2;
    bGameOver = false;

    PrintLine (TEXT("Guess the %i letter word!"), HiddenWord.Len());
    // PrintLine(TEXT("The HiddeWord is: %s"), *HiddenWord); //Debug Line to know the hidden word
    PrintLine (TEXT("You have %i lives"), Lives);
    PrintLine (TEXT("Now, type down your guess and \npress enter to continue...")); //Prompt Player for guess

IsIsogram(HiddenWord);
}
void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again"));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have Won"));
        EndGame();
        return;
    }
    if (Guess.Len() != HiddenWord.Len())
    {
            PrintLine(TEXT("The Hidden word is %i letters long"), HiddenWord.Len());
            PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
            return;
    }
    //Check Isogram
    if (!IsIsogram(Guess))
    {
         PrintLine(TEXT("Oh no no, no repeating letters, try again..."));
         return;
    }
          //Remove Life
        PrintLine(TEXT("Lost a life!"));
        --Lives;

        if(Lives <= 0)
        {
            ClearScreen();
            PrintLine(TEXT("I dind't want to do it but man... *Gunshot*"));
            PrintLine(TEXT("Hahaha, The hidden word was: %s, now die."), *HiddenWord);
            EndGame();
            return;
        } 
        //Show the player bulls and cows
        
    FBullCowCount Score = GetBullCows(Guess);
    PrintLine(TEXT("You hve %i Bulls and %i Cows"), Score.Bulls, Score.Cows);   
    }

    bool UBullCowCartridge::IsIsogram(const FString& Word) const
    {

        for (int32 Index = 0; Index < Word.Len(); Index++)
        {
            for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
        }
        return true;
    }

    TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
        
        TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        if (Word.Len() >= 4 && Word.Len() <= 8)
        {
            if (IsIsogram(Word))
            {
                ValidWords.Emplace(Word);
            }
        }    
    }    
    return ValidWords;
}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;
    
    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if (Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            Count.Bulls++;
            continue;
        }
        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
        {
            if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
            {
                Count.Cows++;
                break;
            }   
        }   
    }
    return Count;
}
     
// for (; Comparison < Word.Len(); Comparison++)
    // {
    //     if (Word[Index] == Word[Comparison])
    //     {
    //         return false;
    //     }
    // }
   
    
    //For each letter
    // Start at element [0]
    // Compare agaisnt the next letter.
    // Until we reach [Word.Len() -1]
    // if any letters are the same return false.