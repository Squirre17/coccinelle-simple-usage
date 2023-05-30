```shell
spatch ex.cocci test.c > test.diff
```

notice that ending bracket must with tab
```diff
@@ expression E1,E2,E3; @@
- pci_map_single(E1,
+ dma_map_single(&E1->dev,
E2, E3,
(
- PCI_DMA_BIDIRECTIONAL
+ DMA_BIDIRECTIONAL
|
- PCI_DMA_TODEVICE
+ DMA_TO_DEVICE
|
- PCI_DMA_FROMDEVICE
+ DMA_FROM_DEVICE
|
- PCI_DMA_NONE
+ DMA_NONE_DEVICE
)
    )               <<-[1] 

```

Break line or not the original text will not affect the match
```c
    dev->phys_dma_addr =
        pci_map_single(dev->pci_dev, (void *)buf, R852_DMA_LEN,
            PCI_DMA_FROMDEVICE);

    dev->phys_dma_addr =
        pci_map_single(dev->pci_dev, 
            (void *)buf, R852_DMA_LEN,
            PCI_DMA_FROMDEVICE);
```

use disjunction to replace all macros
```diff
(
- PCI_DMA_BIDIRECTIONAL
+ DMA_BIDIRECTIONAL
|
- PCI_DMA_TODEVICE
+ DMA_TO_DEVICE
|
- PCI_DMA_FROMDEVICE
+ DMA_FROM_DEVICE
|
- PCI_DMA_NONE
+ DMA_NONE_DEVICE
)
```

or split into two match rules
```diff
@@ expression E1,E2,E3,E4; @@
- pci_map_single(E1,
+ dma_map_single(&E1->dev,
E2, E3, E4)


@@ expression E1,E2,E3; @@
dma_map_single(E1, E2, E3,
(
- PCI_DMA_BIDIRECTIONAL
+ DMA_BIDIRECTIONAL
|
- PCI_DMA_TODEVICE
+ DMA_TO_DEVICE
|
- PCI_DMA_FROMDEVICE
+ DMA_FROM_DEVICE
|
- PCI_DMA_NONE
+ DMA_NONE_DEVICE
)
    )
```