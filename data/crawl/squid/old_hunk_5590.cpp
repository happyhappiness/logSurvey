	    printf("ERR\n");
	    continue;
	}
	if (debug) printf("Binding OK\n");
	if (searchLDAP(ld, group, user, grouprdn) != 0) {
	    if (tryagain) {
		tryagain = 0;
