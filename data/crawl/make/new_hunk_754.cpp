}

#ifndef WINDOWS32

/* EMX: Start a child process. This function returns the new pid.  */
# if defined __MSDOS__ || defined __EMX__
int
child_execute_job (int stdin_fd, int stdout_fd, char **argv, char **envp)
{
