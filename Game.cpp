#include <iostream>
#include <ctime>

/// Outputs level description to the terminal.
/// Takes user input (answer) and checks against level answer.
/// Increments level counter `CurrentLevel` when level is completed.
void PlayLevel(int *CurrentLevel)
{
  const int CodeA = rand() % *CurrentLevel + *CurrentLevel;
  const int CodeB = rand() % *CurrentLevel + *CurrentLevel;
  const int CodeC = rand() % *CurrentLevel + *CurrentLevel;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;  

  std::cout << std::endl << "- LEVEL " << *CurrentLevel << " -" << std::endl << std::endl;;
  std::cout << "The code adds up to: " << CodeSum << std::endl;
  std::cout << "The code multiplies to: " << CodeProduct << std::endl;
  
  bool IsAnswerCorrect = false;
  while (!IsAnswerCorrect) {

    std::cout << std::endl << "Enter your guess:" << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    IsAnswerCorrect = GuessSum == CodeSum && GuessProduct == CodeProduct;

    if (IsAnswerCorrect)
    {
      std::cout << std::endl << "✅ Nice!" << std::endl;
    } else {
      std::cout << std::endl << "❌ Nope! Okay, let's try again." << std::endl;
    }
  }

  *CurrentLevel += 1;
}

/// Loops the game until all level are played.
/// Sets `IsGameComplete` when last level was completed.
void Play(bool *IsGameComplete)
{
  
  int CurrentLevel = 1;
  int MaxLevel = 3;

  while (CurrentLevel <= MaxLevel)
  {
    PlayLevel(&CurrentLevel);
  }

  *IsGameComplete = true;
}

/// Introduces the game and initiates the game play.
int main() 
{
  std::cout << "You woke up in a locked up room. To escape you need to enter the right code!" << std::endl;
  std::cout << "Enter a three digit code to escape the room." << std::endl;
  
  // Seed randomizer
  srand(time(NULL));

  bool isGameComplete = false;
  
  while(!isGameComplete)
  {
    Play(&isGameComplete);
  }

  std::cout << std::endl << "Congratulations! You beat the game!";

  return 0;
}