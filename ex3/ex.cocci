@@
expression E;
identifier F;
@@

- hwif->hwif_data = E;
+ ide_set_hwifdata(hwif, E);

@@
expression E;
identifier F;
@@

- E = hwif->hwif_data;
+ E = ide_get_hwifdata(hwif);