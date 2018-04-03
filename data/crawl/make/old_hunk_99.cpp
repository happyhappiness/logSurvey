  /* The signal handler must called only once! */
  signal (SIGCHLD, SIG_DFL);
#endif

  /* This causes problems if the SIGCHLD interrupts a printf().
  DB (DB_JOBS, (_("Got a SIGCHLD; %u unreaped children.\n"), dead_children));
  */
}

extern pid_t shell_function_pid;
