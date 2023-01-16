## GET NEXT LINE

#### Mandatory part

| Function name     | get_next_line                                                 |
|-------------------|---------------------------------------------------------------|
| Prototype         | char *get_next_line(int fd);                                  |
| Turn in files     | get_next_line.c, get_next_line_utils.c, get_next_line.h       |
| Parameters        | fd: The file descriptor to read from                          |
| Return value      | Read line: correct behavior. NULL: nothing to read/error      |
| External functs.  | read, malloc, free                                            |
| Descripton        | Write a function that returns a line read from a file dscrptr |

* Repeated calls (e.g., using a loop) to your get_next_line() function should let you read text file pointed to by the file descriptor, one line at a time.
* Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
* Make sure that your function works as expected both when reading a file and when reading from the standard input.
* **Please note** that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.
* Your header file **get_next_line.h** must at least contain the prototype of the get_next_line() function.
* Add all the helper functions you need in the **get_next_line_utils.c file.
* Because you will have to read files in get_next_line(), add this option to your compiler call: ``` -D BUFFER_SIZE=n ```. It will define the buffer size for **read()**. The buffer size value will be modified by your peer-evaluatrs and the Moulinette in order to test your code.
*It must be able to compile with and without the -D BUFFER_SIZE flag in addition to the usual flags. Default value is free of choice.*
* The code will be compiled ad follows (buffer size of 42 is used as an example):
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```
* We consider that **get_next_line()** has an undefined behavior if the file pointed by the descriptor changed since the last call whereas **read()** didn't reach the end of file.
* We also consider that **get_next_line()** has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.

*Does the function still work if BUFFER_SIZE value is **9999**? If it is **1**? **10000000**? Do you know why?*

**Important**: Try to read as little as possible each time get_next_line() is called. If you encounter a new line, you have to return the current line. Don't read the whole file and then process each line.

**FORBIDDEN**:

* You are nt allowed to use your **libft** in this project.
* **lseek()** is forbidden.
* Global variables are forbidden.


## Bonus part

This project is straightforward and doesn' allow complex bonuses. However, we trust your creativity. If you completed the mandatory part, give a try to this bonus part.

Here are the bonus part requirements:

* Develop get_next_line() using only one static variable.
* Your get_next_line() can manage multiple file descriptors at the same time. For example, if you can read the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd. This means that you should be able to callg et_next_line() to read from fd 3, then fd 4, then fd 5, then once again 4, once 5 and so forth. Append the _bonus.[c\h] suffix to the bonus part files. It means that, in addition to the mandatory part files, you will turn in the 3 following files:
* get_next_line_bonus.c
* get_next_line_bonus.h
* get_next_line_utils_bonus.c

**Important note**: *The bonus aprt will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you ahve not passed ALL mandatory requirements, your bonus part will not be evaluated at all.