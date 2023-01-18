### What are static variables?

- Static variables are variables initialized only once. The compiler persists with the variable until the end of the program. Static variables can be defined inside or outside the function. They are local to the block. The default value of static variables is zero and are alive until the execution of the program.

```C
static data_type var_name = var_value;
```

example:

```C
#include <stdio.h>
int fun()
{
	static int count = 0;
	count++;
	return count;
}

int main()
{
	printf("%d ", fun());
	printf("%d ", fun());
	return (0);
}
```


