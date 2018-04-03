	"			be allowed to authenticate.\n");
    fprintf(stderr,
	"-p			Verify primary user group as well\n");
    fprintf(stderr,
	"-s			Strip NT domain from usernames\n");
}


int
main(int argc, char *argv[])
{
    char *user, *suser, *p;
    char buf[BUFSIZE];
    char *grents[MAX_GROUP];
    int check_pw = 0, ch, i = 0, j = 0, strip_dm = 0;

    /* make standard output line buffered */
    setvbuf(stdout, NULL, _IOLBF, 0);

    /* get user options */
    while ((ch = getopt(argc, argv, "spg:")) != -1) {
  	switch (ch) {
	case 's':
	    strip_dm = 1;
	    break;
	case 'p':
	    check_pw = 1;
	    break;
