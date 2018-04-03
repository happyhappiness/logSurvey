{
    pid_t pid;
    int  status = signo; // to stop GNU from complaining...

    int saveerr = errno;
    while ( (pid = waitpid( -1, &status, WNOHANG )) > 0 ) {
        if ( WIFEXITED(status) ) {
            fprintf( stderr, "child (pid=%ld) reaped, status %d\n%c",
                      (long) pid, WEXITSTATUS(status), 0 );
        } else if ( WIFSIGNALED(status) ) {
            fprintf( stderr, "child (pid=%ld) died on signal %d%s\n%c",
                      (long) pid, WTERMSIG(status),
#ifdef WCOREDUMP
                      WCOREDUMP(status) ? " (core generated)" : "",
