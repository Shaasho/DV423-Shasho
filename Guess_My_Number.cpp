// Jair Guadalupe Medina Enciso - Zap580
#include <Windows.h>
#include <iostream>
#include <random>
#include "Guess_My_Number.h"


void GuessMyNumber::Start_Guess_My_Number()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // Get console handle
    //A random number generator that produces non-deterministic random numbers, if supported.
    std::random_device randomDevice;
    //mt19937 produces a sequence of 32-bit integers
    std::mt19937 rng(randomDevice());
    std::uniform_int_distribution<std::mt19937::result_type> dist100(1, 100); // distribution in range [1, 100]
    //Random Assignation
    int randomNumber = dist100(rng);
    //Initialization of variables
    bool first_menu = true;
    bool second_menu = true;
    int userNumber = 0;
    int difference = 0;

    std::cout << "What's up buddy!! Wanna guess my number??\n";

    while (second_menu) {

        while (first_menu)
        {
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Set text color back to default
            std::cout << "It gotta be between 1 and 100!! \nGO AHEAD: \n";
            std::cin >> userNumber;

            if (userNumber >= 1 && userNumber <= 100) {
                first_menu = false;
            }
            else {
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY); // Set text color to red
                std::cout << "MY MAN!! that is not a valid number! >:( \n\n";
            }
        }

        //Determines if number is higher or lower than the number generated
        if (userNumber < randomNumber) {
            difference = abs(userNumber - randomNumber);
            if (difference <= 5) {
                SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Set text color to green
                std::cout << "\nYour number is low, but it is very close!\n";
            }
            else {
                if (difference <= 15) {
                    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Set text color to yellow
                    std::cout << "\nYour number is low, but it is close!\n";
                }
                else {
                    if (difference <= 25) {
                        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN); // Set text color to dark yellow
                        std::cout << "\nYour number is low, but it is kinda close!\n";
                    }
                    else {
                        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY); // Set text color to red
                        std::cout << "\nYour number is too low!\n";
                    }
                }
            }
            first_menu = true;
        }
        if (userNumber > randomNumber) {
            difference = abs(userNumber - randomNumber);
            if (difference <= 5) {
                SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Set text color to green
                std::cout << "\nYour number is high, but it is very close!\n";
            }
            else {
                if (difference <= 15) {
                    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Set text color to yellow
                    std::cout << "\nYour number is high, but it is close!\n";
                }
                else {
                    if (difference <= 25) {
                        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN); // Set text color to dark yellow
                        std::cout << "\nYour number is high, but it is kinda close!\n";
                    }
                    else {
                        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY); // Set text color to red
                        std::cout << "\nYour number is too high! \n";
                    }
                }
            }
            first_menu = true;
        }
        //The user guesses the number
        if (userNumber == randomNumber) {
            SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Set text color to green
            std::cout << "\nYOU GOT IT MATE! \nIt was " << userNumber << " indeed!!\n";
            second_menu = false;
        }

    }
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Set text color back to default
    std::cout << "Hope u had fun c:\n";
    std::cout << "Press any key to continue...\n";
    system("pause > null");

    return;
}