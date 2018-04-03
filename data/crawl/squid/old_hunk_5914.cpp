    /* Add to the given hash table 'hid' */
    new = calloc(1, sizeof(hash_link));
    if (!new) {
	fprintf(stderr,"calloc failed!\n");
	print_stats();
	exit(1);
    }
