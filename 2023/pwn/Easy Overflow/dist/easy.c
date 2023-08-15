#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int id = 0;
    char name[16] = "";

    printf("Input your name: ");
    gets(name);
    printf("Your name is %s with ID %d.\n", name, id);

    if (id == 1179402567) {
        printf("%s\n", argv[1]);
    }

    return 0;
}