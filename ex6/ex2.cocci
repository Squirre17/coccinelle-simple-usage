@@ expression e, e1; identifier f; @@
* e = malloc(...);
... when != e == NULL
    when != e != NULL
    when != e = e1
+   if(e == NULL)
+       panic("malloc");
* e->f