#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    void *p = NULL;
    if (!(p = malloc(sizeof(int))))
        exit(1);
    if ((p = malloc(sizeof(int))) == NULL)
        exit(1);
    return 0;
}
