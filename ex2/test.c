#include <malloc.h>
/* This defines the direction arg
to the DMA mapping routines. */
#define PCI_DMA_BIDIRECTIONAL 0
#define PCI_DMA_TODEVICE 1
#define PCI_DMA_FROMDEVICE 2
#define PCI_DMA_NONE 3

enum dma_data_direction {
    DMA_BIDIRECTIONAL = 0,
    DMA_TO_DEVICE = 1,
    DMA_FROM_DEVICE = 2,
    DMA_NONE = 3,
};
struct Dev {
    int phys_dma_addr;
    int pci_dev;
};

#define R852_DMA_LEN 1

const int do_read = 1;

int pci_map_single(int a , void *buf, int b, int c) {
    return 1;
}

int dma_map_single(int *a , void *buf, int b, int c) {
    return 1;
}

int main(int argc, char const *argv[])
{
    struct Dev *dev = (struct Dev *)malloc(sizeof(struct Dev));
    char buf[0x10];

    dev->phys_dma_addr =
        pci_map_single(dev->pci_dev, 
            (void *)buf, R852_DMA_LEN,
            PCI_DMA_FROMDEVICE);

    return 0;
}

