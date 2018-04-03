void
fatal_dump(const char *message)
{
    fprintf(stderr, "Fatal: %s",message);
    exit (1);
}

void
fatal(const char *message)
{
    fprintf(stderr, "Fatal: %s", message);
    exit (1);
}

