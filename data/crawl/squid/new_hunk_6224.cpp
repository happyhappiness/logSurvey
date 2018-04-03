		ptr = buff + 8;
		while (isspace(*ptr))
		    ptr++;
		curr->comment = xstrdup(ptr);
	    } else if (!strncmp(buff, "DEFAULT:", 8)) {
		ptr = buff + 8;
		while (isspace(*ptr))
		    ptr++;
		curr->default_value = xstrdup(ptr);
	    } else if (!strncmp(buff, "DEFAULT_IF_NONE:", 16)) {
		ptr = buff + 16;
		while (isspace(*ptr))
		    ptr++;
		curr->default_if_none = xstrdup(ptr);
	    } else if (!strncmp(buff, "LOC:", 4)) {
		if ((ptr = strtok(buff + 4, WS)) == NULL) {
		    printf("Error on line %d\n", linenum);
		    exit(1);
		}
		curr->loc = xstrdup(ptr);
	    } else if (!strncmp(buff, "TYPE:", 5)) {
		if ((ptr = strtok(buff + 5, WS)) == NULL) {
		    printf("Error on line %d\n", linenum);
		    exit(1);
		}
		curr->type = xstrdup(ptr);
	    } else if (!strncmp(buff, "IFDEF:", 6)) {
		if ((ptr = strtok(buff + 6, WS)) == NULL) {
		    printf("Error on line %d\n", linenum);
		    exit(1);
		}
		curr->ifdef = xstrdup(ptr);
	    } else if (!strcmp(buff, "DOC_START")) {
		state = sDOC;
	    } else if (!strcmp(buff, "DOC_NONE")) {
