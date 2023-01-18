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

- A static variable remains in memory while the program is running whilst a normal variable gets cleared when the function call is over.
- Static variables are allocated memory in data segment, not in the stack segment.
- Static variables (like global variables) are initialized as 0 if not initialized explicitly.
- In C, static variables can only be initialized using constant literals.
- Static global variables and functions are also possible in C/C++. The purpose of these is to limit the scope of a variable or function to a file.
- Static variables should not be declared inside structures.

