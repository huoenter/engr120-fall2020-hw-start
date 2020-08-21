# Coding Style

First make sure `checker` file in the same folder as your c files. To run the
style check: `python checker hw1.c`. If you are given a Makefile, `make`.

I listed all the errors below and their common causes and fixes.

## TABS

**Cause**: having tabs in your source file

**Fix**:

If using repl.it, click on the gear icon to set indent type to `space` and
indent size to `4`.

If using other editors, please follow their specific instructions. The word for
using spaces instead of tabs is called "expanding tabs". Simply typing 4 spaces
is a simple solution.

NOTE: If you have existing tabs, you must change them after getting the right
editor settings.

## LINE TOO LONG

**Cause**: The length of a line in the source code exceeds 80 characters

**Fix**:

```c
int a = b + c;
/* => */
int a = b +
        c;
```

```c
printf("long long long long long long");
/* => */
printf("long long long"
       "long long long");
```

## PUT SPACE AFTER COMMA

**Cause**: Example

```c
int a,b;   /* bad */
printf("%d%d",a,b); /* bad */
add(3,4); /* bad */
```

**Fix**

```c
int a, b;
printf("%d%d", a, b);
add(3, 4);
```

## PUT SPACE AROUND OPERATORS

**Cause**: Example

```c
int a = 1+3;
if (a<b) {}
```

**Fix**

```c
int a = 1 + 3;
if (a < b) {}
```

## DON'T USE C++ COMMENTS

**Cause**: `//` is for c++

```c
int b; // do not use this
```

**Fix**

```c
int b; /* a new variable */
```

## PUT SPACE AFTER OPEN COMMENT

**Cause**

```c
int a; /*declare a */
```

**Fix**

```c
int a; /* declare a */
```

## PUT SPACE BEFORE CLOSE COMMENT

Similar

## PUT SPACE BETWEEN `)` AND `{`

**Cause**

```c
if (a > b){
}
```

**Fix**

```c
if (a > b) {
}
```

## PUT SPACE/NEWLINE AFTER SEMICOLON

**Cause**

```c
int a;int b;
```

**Fix**

```c
int a; int b;
/* OR */
int a;
int b
```

## Other

These will not be checked automatically but please pay attention.

* Opening bracket on a new line for functions

```c
int add(a, b)
{
}
```

* On the same line otherwise

```c
if (a > b) {
}

if (a > b) {
} else {
}

while (a > b) {
}
```
