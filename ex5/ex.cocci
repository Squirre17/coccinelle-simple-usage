@@ expression X; statement S1, S2; @@
    if(
-       !X
+       X == NULL        
    ) S1 else S2

@ is_null @ identifier e1; expression e2; statement S1, S2; @@
+   e1 = e2;
    if (
-       (e1 = e2)
+       e1 
        == NULL) S1 else S2