#include <iostream>

void PrintIntroduciton(int Difficulty)
{
	// Print Story
	std::cout << "\n\nYou are a virus made to infect global computer networks.\n";
	std::cout << "Infect more networks to make yourself more powerful.\n";
	std::cout << "You are currently on a level " << Difficulty << " network.\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduciton(Difficulty);

	// Declaring Variables 
	const int EncryptionA = rand();
	const int EncryptionB = rand();
	const int EncryptionC = rand();

	// Creates encryption hints
	const int EncryptionSum = EncryptionA + EncryptionB + EncryptionC;
	const int EncryptionProduct = EncryptionA * EncryptionB * EncryptionC;

	// Print output to terminal
	std::cout << std::endl;
	std::cout << "- The backdoors are protected by a 3 digit encryption";
	std::cout << "\n- The encryptions add-up to: " << EncryptionSum;
	std::cout << "\n- The product of the encryption is: " << EncryptionProduct;

	std::cout << std::endl;

	// Player guess and repeating of guess
	int PlayerGuess1, PlayerGuess2, PlayerGuess3;
	std::cin >> PlayerGuess1 >> PlayerGuess2 >> PlayerGuess3;

	// Player guess is add and multiplied
	const int GuessSum = PlayerGuess1 + PlayerGuess2 + PlayerGuess3;
	const int GuessProduct = PlayerGuess1 * PlayerGuess2 * PlayerGuess3;

	std::cout << std::endl;

	//Logic to determine right and wrong guesses
	if (GuessSum == EncryptionSum && GuessProduct == EncryptionProduct)
	{
		std::cout << "Network accessed... Virus spreading...\n";
		return true;
	}
	else
	{
		std::cout << "Access denied... Try again...\n";
		return false;
	}
}
 


int main()
{
	int LevelDifficulty = 1;
	const int MaxLevel = 10;

	while (LevelDifficulty <= MaxLevel)  // Loop game until all levels are complete
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // Clears any errors
		std::cin.ignore(); // Discards the buffer 

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	
	std::cout << "You have infected networks world wide... Congratulations...\n";
	return 0;
}
