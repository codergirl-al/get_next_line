### What are static variables?
<details>
<summary> Static variables are variables initialized only once... </summary>
- The compiler persists with the variable until the end of the program. Static variables can be defined inside or outside the function. They are local to the block. The default value of static variables is zero and are alive until the execution of the program.

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
</details>

### Working with files in C

A file is a container in computer storage devices used for storign data.

Why are files needed?
- We need to preserve our data even when the program terminates.
- Handling large amounts of data.
- Moving data from one computer to another without changing it.

There are two types of files: Text and binary files.

<details>
<summary> Text files </summary>
Text files are the normal .txt files. They are easy to create in any simple text editor such as Notepad. When opening them , we can see all the content as plain text. This can easily be edited and deleted.
</details>

<details>
<summary> Binary files </summary>
Binary files are mostly the .bin files in the computer. Instead of storing the data in plain text, they store it in binary form (0s and 1s). They can hold a higher amount of data which is more secured, however though, harder to read.
</details>

#### File Operations:
In c you can perform four major operations on files, either text or binary:
- Creating a new file.
- Opening an existing file.
- Closign a file.
- Reading/Writing information on a file.

#### Working with files:

- Declaring a pointer of type file.

FILE *fptr;

- Opening a file.

ptr = fopen("fileopen", "mode");
for example:
fopen("E:\\program\\newprogram.txt", "w"); // w meaning WRITE
fopen("E:\\program\\oldprogram.bin", "rb"); // rb meaning READ BINARY

Opening Modes in Standard I/O:

| Mode		| Meaning of Mode					| During Inexistence of file				|
|-----------|-----------------------------------|-------------------------------------------|
| r			| Open for reading					| fopen() returns NULL						|
| rb		| Open for reading in binary mode	| fopen() returns NULL						|
| w			| Open for writing					| Create file, otherwise overwrite content	|
| wb		| Open for writing in binary mode	| Create file, otherwise overwrite content	|
| a			| Open for append data on the end	| Create file								|
| ab		| Open for append on binary			| Create file								|
| r+		| Open for both reading and writing	| fopen() returns NULL						|
| rb+		| == in binary mode					| fopen() returns NULL						|
| w+		| Open for both reading and writing	| Create file, otherwise overwrite content	|
| wb+		| == in binary mode					| Create file, otherwise overwrite content	|
| a+		| Open for both reading & appending | Create file								|
| ab+		| == in binary mode					| Create file								|

- Closing a file

fclose(fptr);

- Reading and writign to a text file

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	FILE *fptr;

	// use appropriate location when/if using MacOS or Linux
	fptr = fopen("C:\\program.txt", "w");

	if (fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}

	printf("Enter num: ");
	scanf("%d", &n);

	fprintf(fptr, "%d", n);
	fclose(fptr);

	return (0);
}
```