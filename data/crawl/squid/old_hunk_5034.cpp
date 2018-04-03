DoOneRequest(char *buf)
{
    RequestData requestData;
    ParseBuffer (buf, &requestData);
    if (!requestData.parsed) {
	printf ("ERR\n");
	return;
    }
    OutputHHA1(&requestData);
}

int
main(int argc, char **argv)
{
    char buf[256];
    setbuf(stdout, NULL);
    ProcessArguments (argc, argv);
    while (fgets(buf, 256, stdin) != NULL)
	DoOneRequest (buf);
    exit(0);
}
