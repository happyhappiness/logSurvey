  /* The signal handler must called only once! */
  signal (SIGCHLD, SIG_DFL);
#endif
}

extern pid_t shell_function_pid;
