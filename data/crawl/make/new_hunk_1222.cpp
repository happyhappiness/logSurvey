  ++dead_children;

  if (debug_flag)
    printf ("Got a SIGCHLD; %u unreaped children.\n", dead_children);
}


extern int shell_function_pid, shell_function_completed;

