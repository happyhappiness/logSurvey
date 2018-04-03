        /* parent */
        openlog(APP_SHORTNAME, LOG_PID | LOG_NDELAY | LOG_CONS, LOG_LOCAL4);

        squid_signal(SIGINT, SIG_IGN, SA_RESTART);

#if _SQUID_NEXT_

        pid = wait3(&status, 0, NULL);

#else

        pid = waitpid(-1, &status, 0);

#endif
        // Loop to collect all stopped kids before we go to sleep below.
        do {
            Kid* kid = TheKids.find(pid);
            if (kid) {
                kid->stop(status);
                if (kid->calledExit()) {
                    syslog(LOG_NOTICE,
                           "Squid Parent: %s process %d exited with status %d",
                           kid->name().termedBuf(),
                           kid->getPid(), kid->exitStatus());
                } else if (kid->signaled()) {
                    syslog(LOG_NOTICE,
                           "Squid Parent: %s process %d exited due to signal %d with status %d",
                           kid->name().termedBuf(),
                           kid->getPid(), kid->termSignal(), kid->exitStatus());
                } else {
                    syslog(LOG_NOTICE, "Squid Parent: %s process %d exited",
                           kid->name().termedBuf(), kid->getPid());
                }
                if (kid->hopeless()) {
                    syslog(LOG_NOTICE, "Squid Parent: %s process %d will not"
                           " be restarted due to repeated, frequent failures",
                           kid->name().termedBuf(), kid->getPid());
                }
            } else {
                syslog(LOG_NOTICE, "Squid Parent: unknown child process %d exited", pid);
            }
#if _SQUID_NEXT_
        } while ((pid = wait3(&status, WNOHANG, NULL)) > 0);
#else
        }
        while ((pid = waitpid(-1, &status, WNOHANG)) > 0);
#endif

        if (!TheKids.someRunning() && !TheKids.shouldRestartSome()) {
            leave_suid();
