void
usage(void)
{
	fprintf(stderr, "usage: %s: -p port -h host -n max\n", progname);
}

int 
main(argc, argv)
    int argc;
    char *argv[];
{
    int i;
    int c;
