  ++dead_children;

  if (debug_flag)
    printf ("Got a SIGCHLD; %d unreaped children.\n", dead_children);
}

#endif /* WAIT_NOHANG */

extern int shell_function_pid, shell_function_completed;

