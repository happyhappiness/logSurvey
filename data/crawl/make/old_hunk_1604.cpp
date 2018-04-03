      register struct child *lastc, *c;
      int child_failed;

      /* First, check for remote children.  */
      pid = remote_status (&exit_code, &exit_sig, &coredump, 0);
      if (pid < 0)
