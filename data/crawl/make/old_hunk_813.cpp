
#else /* !VMS */

#if !defined (_AMIGA) && !defined (__MSDOS__)
/* UNIX:
   Replace the current process with one executing the command in ARGV.
   STDIN_FD and STDOUT_FD are used as the process's stdin and stdout; ENVP is
   the environment of the new program.  This function does not return.  */

void
child_execute_job (int stdin_fd, int stdout_fd, char **argv, char **envp)
{
