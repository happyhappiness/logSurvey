{
    pid_t pid;
    int  status = signo; // to stop GNU from complaining...
    char line[128];

    int saveerr = errno;
    while ( (pid = waitpid( -1, &status, WNOHANG )) > 0 ) {
        if ( WIFEXITED(status) ) {
            snprintf( line, 128, "child (pid=%ld) reaped, status %d\n%c",
                      (long) pid, WEXITSTATUS(status), 0 );
        } else if ( WIFSIGNALED(status) ) {
            snprintf( line, 128, "child (pid=%ld) died on signal %d%s\n%c",
                      (long) pid, WTERMSIG(status),
#ifdef WCOREDUMP
                      WCOREDUMP(status) ? " (core generated)" : "",
