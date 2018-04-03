    }
    origbuf = buf;
    if (ntlmCheckHeader(&auth->hdr, NTLM_AUTHENTICATE)) {
	fprintf(stderr, "ntlmDecodeAuth: header check fails\n");
	return -1;
    }
    debug("ntlmDecodeAuth: size of %d\n", size);
    debug("ntlmDecodeAuth: flg %08x\n", auth->flags);
    debug("ntlmDecodeAuth: usr o(%d) l(%d)\n", auth->user.offset, auth->user.len);

    if ((p = ntlmGetString(&auth->hdr, &auth->domain, auth->flags)) == NULL)
	p = authenticate_ntlm_domain;

    debug("ntlmDecodeAuth: Domain '%s'.\n", p);

    if ((s = strlen(p) + 1) >= size)
	return 1;
    strcpy(buf, p);

    debug("ntlmDecodeAuth: Domain '%s'.\n", buf);

    size -= s;
    buf += (s - 1);
    *buf++ = '\\';		/* Using \ is more consistent with MS-proxy */

    p = ntlmGetString(&auth->hdr, &auth->user, auth->flags);
    if ((s = strlen(p) + 1) >= size)
	return 1;
    while (*p)
	*buf++ = (*p++);	//tolower

    *buf++ = '\0';
    size -= s;

    debug("ntlmDecodeAuth: user: %s%s\n", origbuf, p);

    return 0;
}


/*
 * options:
 * -d enable debugging.
 * -v enable verbose NTLM packet debugging.
 * -l if specified, changes behavior on failures to last-ditch.
 */
char *my_program_name = NULL;

void
usage()
{
    fprintf(stderr,
	"Usage: %s [-d] [-v] [-h]\n"
	" -d  enable debugging.\n"
	" -v  enable verbose NTLM packet debugging.\n"
	" -h  this message\n\n",
	my_program_name);
}


void
process_options(int argc, char *argv[])
{
    int opt, had_error = 0;

    opterr = 0;
    while (-1 != (opt = getopt(argc, argv, "hdv"))) {
	switch (opt) {
	case 'd':
	    debug_enabled = 1;
	    break;
	case 'v':
	    debug_enabled = 1;
	    NTLM_packet_debug_enabled = 1;
	    break;
	case 'h':
	    usage();
	    exit(0);
	case '?':
	    opt = optopt;
	    /* fall thru to default */
	default:
	    fprintf(stderr, "unknown option: -%c. Exiting\n", opt);
	    usage();
	    had_error = 1;
	}
    }
    if (had_error)
	exit(1);
}


int
main(int argc, char *argv[])
{
    char buf[BUFFER_SIZE];
    char user[256], *p, *decoded = NULL;
    struct ntlm_challenge chal;
    struct ntlm_negotiate *nego;
    char helper_command[3];
    int len;
    char *data = NULL;

    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    my_program_name = argv[0];

    process_options(argc, argv);

    debug("%s build " __DATE__ ", " __TIME__ " starting up...\n", my_program_name);

    while (fgets(buf, BUFFER_SIZE, stdin) != NULL) {
	user[0] = '\0';		/*no usercode */

	if ((p = strchr(buf, '\n')) != NULL)
	    *p = '\0';		/* strip \n */
	if ((strlen(buf) > 3) && NTLM_packet_debug_enabled) {
	    decoded = base64_decode(buf + 3);
	    strncpy(helper_command, buf, 2);
	    helper_command[2] = '\0';
	    debug("Got '%s' from Squid with data:\n", helper_command);
	    hex_dump(decoded, ((strlen(buf) - 3) * 3) / 4);
	} else
	    debug("Got '%s' from Squid\n", buf);

	if (strncasecmp(buf, "YR", 2) == 0) {
	    if (strlen(buf) > 3) {
		nego = (struct ntlm_negotiate *) decoded;
		ntlmMakeChallenge(&chal, nego->flags);
	    } else
		ntlmMakeChallenge(&chal, NEGOTIATE_ASCII);
	    len =
		sizeof(chal) - sizeof(chal.pad) +
		le16toh(chal.target.maxlen);
	    data = (char *) base64_encode_bin((char *) &chal, len);
	    if (NTLM_packet_debug_enabled) {
		printf("TT %s\n", data);
		decoded = base64_decode(data);
		debug("sending 'TT' to squid with data:\n");
		hex_dump(decoded, (strlen(data) * 3) / 4);
	    } else
		SEND2("TT %s", data);
	} else if (strncasecmp(buf, "KK ", 3) == 0) {
	    if (!ntlmCheckHeader((ntlmhdr *) decoded, NTLM_AUTHENTICATE)) {
		if (!ntlmDecodeAuth((struct ntlm_authenticate *) decoded, user, 256)) {
		    lc(user);
		    SEND2("AF %s", user);
		} else {
		    lc(user);
		    SEND2("NA invalid credentials, user=%s", user);
		}
	    } else {
		lc(user);
		SEND2("BH wrong packet type! user=%s", user);
	    }
	}
    }
    exit(0);
}
