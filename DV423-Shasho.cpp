// Jair Guadalupe Medina Enciso - Zap580
#include <Windows.h>
#include <iostream>
#include <random>
#include <cstdlib>

#include "Guess_My_Number.h"

int main()
{
    bool mainMenu = true;
    int optionSelectedMainMenu = 0;

    GuessMyNumber guessMyNumber;

    while (mainMenu) {
        system("cls");
        std::cout << "DV423-Shasho has been executed!\n\n\nPlease Select your practice!:\n";
        std::cout << "0.Exit Program\n1.Guess My Number\n";
        std::cout << "\nPlease enter the number of the desired option:\n";
        std::cin >> optionSelectedMainMenu;

        switch (optionSelectedMainMenu)
        {
        case 1:
            system("cls");
            guessMyNumber.Start_Guess_My_Number();
            break;
        case 0:
            mainMenu = false;
            break;
        }
    }

    return 0;
}