	"			be allowed to authenticate.\n");
    fprintf(stderr,
	"-p			Verify primary user group as well\n");
}


int
main(int argc, char *argv[])
{
    char *user, *p;
    char buf[BUFSIZE];
    char *grents[MAX_GROUP];
    int check_pw = 0, ch, i = 0, j = 0;

    /* make standard output line buffered */
    setvbuf(stdout, NULL, _IOLBF, 0);

    /* get user options */
    while ((ch = getopt(argc, argv, "pg:")) != -1) {
	switch (ch) {
	case 'p':
	    check_pw = 1;
	    break;
