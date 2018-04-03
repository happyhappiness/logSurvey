
        pid = waitpid(-1, &status, WNOHANG);
#endif
        /* no debugs() here; bad things happen if the signal is delivered during _db_print() */
#if HAVE_SIGACTION

    } while (pid > 0);
