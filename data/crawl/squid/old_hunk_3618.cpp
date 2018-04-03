void
fatal_dump(const char *message)
{
    debug (0,0) ("Fatal: %s",message);
    exit (1);
}

void
fatal(const char *message)
{
    debug (0,0) ("Fatal: %s",message);
    exit (1);
}

