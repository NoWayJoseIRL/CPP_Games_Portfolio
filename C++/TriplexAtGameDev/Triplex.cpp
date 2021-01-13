#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are in The Panic Room level " << Difficulty;
    std::cout << " \nYou need to evade the tiles by guessing the numbers, \nNow Make your move.\n\n";

}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and product to the terminal

    std::cout << "\n+ Let me give you a hint: " << CodeProduct <<std::endl;

    //Store player move
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n\nOh, nice dodge, it's super effective!";
        return true;
    }
    else
    {
        std::cout << "\n*** You got crushed by a tile! Hahaha...";
        return false;
    }
}


int main()
{
    srand(time(NULL)); //Creates a new random sequence bsaed on time of the day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)  //Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        
        std::cin.clear(); //Clears any erros
        std::cin.ignore(); //Discards the buffer

       if (bLevelComplete)
       {
           ++LevelDifficulty;
       }
        
 
    }
    std::cout << "\n*** You survived! You are free now...";

    return 0;
    
}