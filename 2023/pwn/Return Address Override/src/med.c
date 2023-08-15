#include <stdio.h>
#include <stdlib.h>

char *FLAG;

void win() {
    puts(FLAG);
}

int getName() {
    char name[128] = "";
    gets(name);
    return 0;
}

int main(int argc, char *argv[]) {
    FLAG = argv[1];
    getName();
}