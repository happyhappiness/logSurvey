     char **argv, **envp;
{
#ifdef VMS
    /* Run the program.  */
    execve (argv[0], argv, envp);
    perror_with_name ("execve: ", argv[0]);
    _exit (EXIT_FAILURE);
#else
  /* Be the user, permanently.  */
  child_access ();

