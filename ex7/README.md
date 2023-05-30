```shell
$ spatch --sp-file ex.cocci test.c
init_defs_builtins: /usr/bin/../lib/coccinelle/standard.h
HANDLING: test.c
[+] rule1's src variable name : src_buf
<coccilib.elems.Location instance at 0x7feb3d4a6780>
[+] test.c:5 rule1 1st fetch
[+] test.c:10 rule1 2nd fetch
```

We can use predefined rule name to get matched varname and position.
```
@ rule1 @
@@

copy_from_user(exp2, (T2)src, size2)@p2

@script:python@
p12 << rule1.p2;
@@


```

• p[0].file is the name of the file represented by p.
• p[0].line is the number, as a string, of the line represented by p.
• p is an array, because there can be many matches.


also can use following to define some python2 snippets
```
@initialize:python@
@@
```



