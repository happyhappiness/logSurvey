    return match;
}

void
process_options(int argc, char *argv[])
{
    int opt;

    while (-1 != (opt = getopt(argc, argv, "d"))) {
	switch (opt) {
	case 'd':
	    debug_enabled = 1;
	    break;
	default:
	    warn("Unknown option: -%c. Exiting\n", opt);
	    exit(1);
	    break;		/* not reached */
	}
