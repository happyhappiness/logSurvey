        pid = waitpid(-1, &status, 0);

#endif
        // Loop to collect all stopped kids before we go to sleep below.
        do {
            Kid* kid = TheKids.find(pid);
            if (kid) {
                kid->stop(status);
                if (kid->calledExit()) {
                    syslog(LOG_NOTICE,
                           "Squid Parent: child process %d exited with status %d",
                           kid->getPid(), kid->exitStatus());
                } else if (kid->signaled()) {
                    syslog(LOG_NOTICE,
                           "Squid Parent: child process %d exited due to signal %d with status %d",
                           kid->getPid(), kid->termSignal(), kid->exitStatus());
                } else {
                    syslog(LOG_NOTICE, "Squid Parent: child process %d exited", kid->getPid());
                }
            } else {
                syslog(LOG_NOTICE, "Squid Parent: unknown child process %d exited", pid);
            }
#ifdef _SQUID_NEXT_
        } while ((pid = wait3(&status, WNOHANG, NULL)) > 0);
#else
        }
        while ((pid = waitpid(-1, &status, WNOHANG)) > 0);
#endif

        if (TheKids.allExitedHappy()) {
            exit(0);
        }

        if (TheKids.allHopeless()) {
            syslog(LOG_ALERT, "Exiting due to repeated, frequent failures");
            exit(1);
        }

        if (TheKids.allSignaled(SIGKILL)) {
            exit(0);
        }

        if (TheKids.allSignaled(SIGINT) || TheKids.allSignaled(SIGTERM)) {
            syslog(LOG_ALERT, "Exiting due to unexpected forced shutdown");
            exit(1);
        }

        squid_signal(SIGINT, SIG_DFL, SA_RESTART);
