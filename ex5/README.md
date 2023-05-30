use this will work
```diff
@ is_null @ identifier e1; expression e2; statement S1, S2; @@
+   e1 = e2;
    if (
-       !(e1 = e2)
+       e1 == NULL
        ) S1 else S2
```

but coccinelle will not recognize `!a` equal to `a == NULL` 

following will failed with `if (!(p = malloc(sizeof(int))))`
```diff
@ is_null @ identifier e1; expression e2; statement S1, S2; @@
+   e1 = e2;
    if (
-       (e1 = e2)
+       e1 
        == NULL) S1 else S2
```

use this to convert all `!X` to `X == NULL`
```diff
@@ expression X; statement S1, S2; @@
    if(
-       !X
+       X == NULL        
    ) S1 else S2

```

