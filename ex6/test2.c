#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct Ptr{
    int a;
}Ptr;

int main(int argc, char const *argv[])
{
    // if (foo == NULL) {
    //     printk ("Error %s", foo->a);
    //     return;
    // }
    Ptr *foo = malloc(1024);
    foo->a = 1;
    return;
}
