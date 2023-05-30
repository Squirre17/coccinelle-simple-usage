#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Ptr{
    int a;
}Ptr;

int main(int argc, char const *argv[])
{
    Ptr *p;
    p = (Ptr *)malloc(sizeof(Ptr));
    memset(p, 0, sizeof(*p));
    p->a = 1;
    return 0;
}
