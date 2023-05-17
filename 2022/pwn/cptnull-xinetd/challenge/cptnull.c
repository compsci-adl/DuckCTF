#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    char input[9];
    char password[9];
    size_t len = 8;

    FILE *urandom = fopen("/dev/urandom", "r");

    printf("                _____                                                                    \n"
           "              .-\" .-. \"-.                                                              \n"
           "            _/ '=(0.0)=' \\_                                                             \n"
           "          /`   .='|m|'=.   `\\                                                           \n"
           "          \\________________ /                                                           \n"
           "      .--.__///`'-,__~\\\\\\\\~`            Ahoy, matey! Me name be Cap'n Null!          \n"
           "     / /6|__\\// 0 (__)-\\\\\\\\       I be hankerin to decrypt me buried treasures,     \n"
           "     \\ \\/--`((   ._\\   ,)))  but that foul blaggart Sir Random, bless his black soul, \n"
           "     /  \\\\  ))\\  -==-  (O)(       'as run the rig and locked it up wit' a password!   \n"
           "    /    )\\((((\\   .  /)))))               Can ye open th' chest for me?               \n"
           "   /  _.' /  __(`~~~~`)__                                                                \n"
           "  //\"\\\\,-'-\"`   `~~~~\\\\~~`\"-.                                                     \n"
           " //  /`\"              `      `\\                                                        \n"
           "//                                                                                       \n"
           "\nPassword: ");

    fgets(input, 8, stdin);
    fread(password, len, 1, urandom);

    /* 
     * Increase the null-byte to at least once per 10s to minimise bruteforce
     * (Not included in code distributed to participants)
     */
    time_t now = time(0);
    if (now % 10 == 0) {
        password[0] = '\0';
    }
    // END of hidden code
    
    if (strcmp(input, password) == 0) {
        system("/bin/cat treasure.txt");
    } else {
        printf("\nAvast! Twas not th' password! The password was %s\n", password);
    }

    return 0;
}