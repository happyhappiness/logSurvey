	} else if (!strcmp(token, "$h_name")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $h_name");
	    i.entry.h_name = xstrdup(token);
	} else if (!strcmp(token, "$h_len")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $h_len");
	    i.entry.h_length = atoi(token);
	} else if (!strcmp(token, "$ipcount")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $ipcount");
	    ipcount = atoi(token);
	    i.addr_count = (unsigned char) ipcount;
	    if (ipcount == 0) {
		i.entry.h_addr_list = NULL;
	    } else {
		i.entry.h_addr_list = xcalloc(ipcount + 1, sizeof(char *));
	    }
	    for (k = 0; k < ipcount; k++) {
		if ((token = strtok(NULL, w_space)) == NULL)
		    fatal_dump("Invalid IP address");
		*(i.entry.h_addr_list + k) = xcalloc(1, i.entry.h_length);
		*((u_num32 *) (void *) *(i.entry.h_addr_list + k))
		    = inet_addr(token);
	    }
	} else if (!strcmp(token, "$aliascount")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
		fatal_dump("Invalid $aliascount");
	    aliascount = atoi(token);
	    i.alias_count = (unsigned char) aliascount;
	    if (aliascount == 0) {
		i.entry.h_aliases = NULL;
	    } else {
		i.entry.h_aliases = xcalloc(aliascount, sizeof(char *));
	    }
	    for (k = 0; k < aliascount; k++) {
		if ((token = strtok(NULL, w_space)) == NULL)
		    fatal_dump("Invalid alias");
		*(i.entry.h_aliases + k) = xstrdup(token);
	    }
	} else if (!strcmp(token, "$ttl")) {
	    if ((token = strtok(NULL, w_space)) == NULL)
