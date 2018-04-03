}				/* ARGSUSED */

static void
catch(int sig)
{
    interrupted = 1;
    fprintf(stderr, "Interrupted.\n");
