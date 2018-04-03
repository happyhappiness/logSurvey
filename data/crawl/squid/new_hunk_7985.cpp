	puts(dead_msg());
}

void death()
{
    fprintf(stderr, "FATAL: Received Segment Violation...dying.\n");
    signal(SIGSEGV, SIG_DFL);
    signal(SIGBUS, SIG_DFL);
    storeWriteCleanLog();
    PrintRusage(NULL, stderr);
    print_warranty();
    abort();
}


void deathb()
{
    fprintf(stderr, "FATAL: Received bus error...dying.\n");
    signal(SIGSEGV, SIG_DFL);
    signal(SIGBUS, SIG_DFL);
    signal(SIGBUS, SIG_DFL);
    storeWriteCleanLog();
    PrintRusage(NULL, stderr);
    print_warranty();
    abort();
}

void rotate_logs(sig)
     int sig;
{
