    interrupted = 1;
    fprintf(stderr, "Interrupted.\n");
}
void
pipe_handler(int sig)
{
	fprintf(stderr,"SIGPIPE received.\n");
}

static void
set_our_signal()
{
#if HAVE_SIGACTION
    struct sigaction sa;
    sa.sa_handler = pipe_handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGPIPE, &sa, NULL) < 0) {
	fprintf(stderr,"Cannot set PIPE signal.\n");
	exit(-1);
    }
#else
    signal(SIGPIPE, pipe_handler);
#endif

}
