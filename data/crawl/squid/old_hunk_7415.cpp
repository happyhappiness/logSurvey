void
fatal(const char *message)
{
    fatal_common(message);
    exit(1);
}