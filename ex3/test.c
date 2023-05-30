#include <malloc.h>
#include "test.h"



int main(int argc, char const *argv[])
{
    ide_hwif_t *hwif = (ide_hwif_t *)malloc(sizeof(ide_hwif_t));
    hwif->hwif_data = NULL;
    return 0;
}
