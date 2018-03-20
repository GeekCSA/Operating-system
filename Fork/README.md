### Background
fork is a command that splits a process into two.

In this way, we can create another process that will work in parallel to the current process, but will be able to operate on another program.

We can change the program on which the process runs by exec commands.

For more information: [link](http://www.elad-horev.org/Teaching/OS1/s1.pdf)

### Description of the program

This code using the fork() system call that generates the following tree:

# ![diagram](https://github.com/GeekCSA/Operating-system/blob/master/Fork/TreeByFork.png?raw=true "Title")

Before each process finishes its execution it prints its process id and the number of
children created throughout its execution.
