#include <iostream>
#include "Random.h"

bool play(int gameNum, int maxGuesses)
{
    for (int guessNum = { 1 }; guessNum <= maxGuesses; ++guessNum)
    {
        int guess = { };
        std::cout << "Guess #" << guessNum << ": ";
        std::cin >> guess;

        if (guess > gameNum)
        {
            std::cout << "Your guess is too high." << '\n';
        }
        else if (guess < gameNum)
        {
            std::cout << "Your guess is too low." << '\n';
        }
        else
        {
            return true;
        }
    }

    return false;
}

bool playAgain()
{
    while (true)
    {
        char ch = {};
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> ch;

        switch (ch)
        {
        case 'y': return true;
        case 'n': return false;
        }
    }
}

int main()
{
    constexpr int maxGuesses = { 7 };
    do
    {
        int gameNum = { Random::get(1, 100) };
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have " << maxGuesses << " tries to guess what it is.\n";
        bool winner = { play(gameNum, maxGuesses) };
        if (winner)
            std::cout << "Correct! You win!\n";
        else
            std::cout << "Sorry, you lose. The correct number was " << gameNum << ".\n";
    } while (playAgain());

    std::cout << "Thank you for playing.";

    return 0;
}


