**This part out of my ability so I can't understand all thing**
# replace the kmalloc + memeset to zero with kzmalloc(userland for simple explain)
```
@ replace @
expression e,e1;
type T;
@@

- e = (T)malloc(e1);
+ e = (T)zalloc(e1);
... when != e != NULL
    when != e == NULL

- memset(e, 0, sizeof(*e));
```

effect
```diff
--- test.c
+++ /tmp/cocci-output-93153-26bc07-test.c
@@ -9,8 +9,7 @@ typedef struct Ptr{
 int main(int argc, char const *argv[])
 {
     Ptr *p;
-    p = (Ptr *)malloc(sizeof(Ptr));
-    memset(p, 0, sizeof(*p));
+    p = (Ptr *)zalloc(sizeof(Ptr));
     p->a = 1;
     return 0;
 }

```



Bad code:
```c
g = kmalloc (sizeof (*g), GFP_KERNEL);
g->next = chains[r_sym].next;
```
must check the vaildity of kmalloc return ptr

- When constraints, e.g. `when != e`, are allowed but the expression e must be represented as a single token.
- `...` matches everything except what is on either side.

