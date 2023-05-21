#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::vector<std::string> words = {"apple", "banana", "orange", "grape", "melon"};
    
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    std::string selectedWord = words[randomIndex];

    int wordLength = selectedWord.length();
    std::string guessedWord(wordLength, '-');

    int attempts = 5;

    std::cout << "Welcome to the Word Guessing Game!" << std::endl;
    std::cout << "Guess the word by entering one letter at a time." << std::endl;

    while (attempts > 0 && guessedWord != selectedWord) {
        std::cout << "Guesses remaining: " << attempts << std::endl;
        std::cout << "Current word: " << guessedWord << std::endl;

        char guess;
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        bool found = false;
        for (int i = 0; i < wordLength; ++i) {
            if (selectedWord[i] == guess) {
                guessedWord[i] = guess;
                found = true;
            }
        }

        if (found) {
            std::cout << "Correct guess!" << std::endl;
        } else {
            std::cout << "Incorrect guess!" << std::endl;
            --attempts;
        }

        std::cout << std::endl;
    }

    if (guessedWord == selectedWord) {
        std::cout << "Congratulations! You guessed the word: " << selectedWord << std::endl;
    } else {
        std::cout << "Game over! The word was: " << selectedWord << std::endl;
    }

    return 0;
}
