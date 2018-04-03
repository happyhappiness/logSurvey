        pid = waitpid(-1, &status, 0);

#endif

        time(&stop);

        if (WIFEXITED(status)) {
            syslog(LOG_NOTICE,
                   "Squid Parent: child process %d exited with status %d",
                   pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            syslog(LOG_NOTICE,
                   "Squid Parent: child process %d exited due to signal %d with status %d",
                   pid, WTERMSIG(status), WEXITSTATUS(status));
        } else {
            syslog(LOG_NOTICE, "Squid Parent: child process %d exited", pid);
        }

        if (stop - start < 10)
            failcount++;
        else
            failcount = 0;

        if (failcount == 5) {
            syslog(LOG_ALERT, "Exiting due to repeated, frequent failures");
            exit(1);
        }

        if (WIFEXITED(status))
            if (WEXITSTATUS(status) == 0)
                exit(0);

        if (WIFSIGNALED(status)) {
            switch (WTERMSIG(status)) {

            case SIGKILL:
                exit(0);
                break;

            case SIGINT:
            case SIGTERM:
                syslog(LOG_ALERT, "Exiting due to unexpected forced shutdown");
                exit(1);
                break;

            default:
                break;
            }
        }

        squid_signal(SIGINT, SIG_DFL, SA_RESTART);
