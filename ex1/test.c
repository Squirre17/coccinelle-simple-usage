#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define B 3
int main(int argc, char const *argv[])
{
    int a = 1;
    if(!a & B) {
        printf("hit\n");
    }
    return 0;
}
