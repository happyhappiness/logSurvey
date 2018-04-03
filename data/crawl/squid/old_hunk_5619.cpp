		/* ignore empty and comment lines */
		(void) 0;
	    } else if (!strncmp(buff, "NAME:", 5)) {
		char *name;
		if ((name = strtok(buff + 5, WS)) == NULL) {
		    printf("Error in input file\n");
		    exit(1);
		}
		curr = calloc(1, sizeof(Entry));
		curr->name = xstrdup(name);
		state = s1;
	    } else if (!strcmp(buff, "EOF")) {
		state = sEXIT;
