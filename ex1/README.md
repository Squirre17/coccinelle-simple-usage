```shell
spatch ex1.cocci test.c > test.diff
```

following cmd will replace source file directly
```shell
spatch --in-place ex1.cocci test.c
```


