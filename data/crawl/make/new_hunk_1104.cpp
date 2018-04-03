  ++dead_children;

  if (debug_flag)
    printf (_("Got a SIGCHLD; %u unreaped children.\n"), dead_children);
}


