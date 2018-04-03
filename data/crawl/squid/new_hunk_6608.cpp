    interrupted = 1;
    fprintf(stderr, "Interrupted.\n");
}

void
pipe_handler(int sig)
{
    fprintf(stderr, "SIGPIPE received.\n");
}

static void
