typedef struct ide_hwif {
    void *hwif_data;
}ide_hwif_t;


static inline void *
ide_get_hwifdata (ide_hwif_t * hwif)
{
    return hwif->hwif_data;
}
static inline void
ide_set_hwifdata (ide_hwif_t * hwif, void *data)
{
    hwif->hwif_data = data;
}