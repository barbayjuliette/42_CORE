# get_next_line

In this project, we have to create the function get_next_line, which should read the text file pointed by the file descriptor, one line at a time.

Each call to the function will return the next line (including \n, if present). If there is nothing else to read, or there was an error, NULL will be returned.
The function works when reading from a file, or from the standard input.

The function can be used with any buffer size.
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

## Learning points

Thanks to this project, I learned about static variables. 
It was also a very useful project, to reuse in the future, and to understand better how to work with files.
This project, seemingly easy, turned out more difficult than expected, in terms of freeing the dynamically allocated memory and returning NULL once we have reached the EOF.
This project was also one of the 2 possible questions for the second exam. This helped me refine my code and understand the logic even better.
