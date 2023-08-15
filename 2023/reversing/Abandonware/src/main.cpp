#include <iostream>
#include "obfuscate.h"

void print_flag()
{
    std::cout << AY_OBFUSCATE("quack{ch4ng3_0n3_l1n3}") << std::endl;
}

bool activation() {
    bool available = false;
    if (available)
    {
        return true;
    }
    return false;
}

int main()
{
    std::cout << "   _________________________________________________________\n  |                                                         |\n  |          ____                                           |\n  |         /$$$$\\                                          |\n  |        /$$/\\$$\\                                         |\n  |       /$$/_ \\$$\\                                        |\n  |      /$$$$$\\ \\$$\\                                       |\n  |      ¯¯¯¯¯¯¯  ¯¯¯                                       |\n  |                                                         |\n  |   ADOOBIE FLAG EXPRESS                                  |\n  |                                                         |\n  |   2010 Release                                          |\n  |   © 2023 Adoobie Systems Incorporated                   |\n  |   All rights reserved.                                  |\n  |                                                         |\n  |   Reading Preferences …                                 |\n  |                                                         |\n   _________________________________________________________ \n\n\n\n ACTIVATION WIZARD\n ______________________________________________________________\n\n 1.	Evaluate this product (*)\n 2.	Activate with licence key\n 3.	Activate using your Adoobie Creative Cloud account (*)\n\n * an active network connection is required to use this action\n ______________________________________________________________\n\n\n Enter your selection: "; 
   
    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "\nCould not connect to server. Please restart the launcher and try again.\n";
    } else if (choice == 2)
    {
        if (activation()) 
        {
            print_flag();
        }
        else
        {
            std::cout << "\nCould not validate licence. Please restart the launcher and try again.\n";
        }
    } else if (choice == 3)
    {
        std::cout << "\nCould not connect to network. Please restart the launcher and try again.\n";
    } else {
        std::cout << "\nActivation failed. Please restart the launcher and try again.\n";
    }

    return 0;
}