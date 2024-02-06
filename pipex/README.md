# Pipex

In this project, we learned about processes and pipes.
We had to create a program that behaves like a pipe.

## Examples
 ./pipex infile "ls -l" "wc -l" outfile
 Behaves just like: < infile ls -l | wc -l > outfile

 ./pipex infile "grep a1" "wc -w" outfile
 Behaves just like: < infile grep a1 | wc -w > outfile
