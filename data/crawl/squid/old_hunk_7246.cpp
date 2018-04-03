#else
	pid = waitpid(-1, &status, WNOHANG);
#endif
	debug(21, 3, "sig_child: Ate pid %d\n", pid);
#if HAVE_SIGACTION
    } while (pid > 0);
#else