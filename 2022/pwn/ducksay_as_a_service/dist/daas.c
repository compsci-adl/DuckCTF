
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int debug = 0;
    char buffer[128];

    printf(
        "  ----------------------------------------------  \n"
        "< Welcome to the Ducksay as a Service remote CLI >\n"
        "  ----------------------------------------------  \n"
        "\n"
        "> "
    );

    scanf("%[^\n]", buffer);

    if (debug == 0)
    {
        char temp[256];

        for (int i = 0; i < strlen(buffer) * 2 - 1; i += 2)
        {
            temp[i] = '\\';
            temp[i+1] = buffer[i/2];
        }
        
        strcpy(buffer, temp);
    }

    char cmd[256];

    strcpy(cmd, "cowsay -f duck ");
    strcat(cmd, buffer);
    strcat(cmd, " && cat /dev/null");
    system(cmd);
    
    printf("bye!\n");

    return 0;
}
