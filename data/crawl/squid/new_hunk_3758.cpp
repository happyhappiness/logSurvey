death(int sig)
{
    std::cout << "Fatal: Signal " <<  sig;
    exit(1);
}

void
fatal(const char *message)
{
    fprintf(stderr, "FATAL: %s\n", message);
    exit(1);
}

/* end stub functions */

