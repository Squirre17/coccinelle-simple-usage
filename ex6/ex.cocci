@ replace @
expression e,e1;
type T;
@@

- e = (T)malloc(e1);
+ e = (T)zalloc(e1);
... when != e != NULL
    when != e == NULL

- memset(e, 0, sizeof(*e));