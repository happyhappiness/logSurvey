    return domain;
}

char *
process_options(int argc, char *argv[])
{
    int opt;
    char *target_domain = NULL;

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
	if (optind >= argc - 1) {
	    target_domain = argv[optind];
	    warn("target domain is %s\n", target_domain);
	}
    }
    return target_domain;