Python file generator example.

http://nedbatchelder.com/code/cog/index.html#h_installation

E.g.
```python -m cogapp -d -o result.c src.c```

Result:
```
#include <stdio.h>

int main() {

printf("a = 1");
printf("b = 2");
printf("c = 3");
printf("d = 4");
printf("e = 5");

printf("Some non generated text");

}
```
