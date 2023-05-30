Replace uses of hwif->hwif data by calls to these function(getter/setter).


if I use this
```diff
@@ ide_hwif_t *hwif; expression data; @@
- hwif->hwif_data = data
+ ide_set_hwifdata(hwif, data)

@@ ide_hwif_t *hwif; @@
- hwif->hwif_data
+ ide_get_hwifdata(hwif)
```

the diff output like following
```diff
--- test.c
+++ /tmp/cocci-output-85959-45f8ba-test.c
@@ -6,17 +6,17 @@ typedef struct ide_hwif {
 static inline void *
 ide_get_hwifdata (ide_hwif_t * hwif)
 {
-    return hwif->hwif_data;
+    return ide_get_hwifdata(hwif);
 }
 static inline void
 ide_set_hwifdata (ide_hwif_t * hwif, void *data)
 {
-    hwif->hwif_data = data;
+    ide_set_hwifdata(hwif, data);
 }
 
 int main(int argc, char const *argv[])
 {
     ide_hwif_t *hwif = (ide_hwif_t *)malloc(sizeof(ide_hwif_t));
-    hwif->hwif_data = NULL;
+    ide_set_hwifdata(hwif, NULL);
     return 0;
 }
```

getter and setter is reside in header file which shouldn't apply to coccinelle match rule.

so split it out.

