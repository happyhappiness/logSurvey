      job_rfd = -1;
    }

  DB (DB_JOBS, (_("Got a SIGCHLD; %u unreaped children.\n"), dead_children));
}
#endif  /* !__EMX__ */

extern int shell_function_pid, shell_function_completed;

