Python file generator example, see http://nedbatchelder.com/code/cog/index.html#h_installation

```python -m cogapp -d -o result.c src.c```

Result:
```C
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
