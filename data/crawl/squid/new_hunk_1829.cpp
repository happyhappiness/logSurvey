int
main(int argc, char *argv[])
{
    const char *Token;
    int count;

    if (argc < 2) {
        fprintf(stderr, "%s| %s: Error: No proxy server name given\n",
                LogTime(), PROGRAM);
        return 99;
    }
    if (argc == 3) {
        count = atoi(argv[2]);
