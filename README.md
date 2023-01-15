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

