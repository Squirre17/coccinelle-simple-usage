#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct Ptr{
    int a;
}Ptr;
int main(int argc, char const *argv[])
{
    Ptr *bar;
    bar = (Ptr *)malloc(sizeof(Ptr));
    if(bar == NULL)
        bar++;
    bar->a = 1;
    return 0;
}
