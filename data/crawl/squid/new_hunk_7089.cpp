		while (isspace(*ptr))
		    ptr++;
		curr->default_value = strdup(ptr);
	    } else if (!strncmp(buff, "DEFAULT_IF_NONE:", 16)) {
		ptr = buff + 16;
		while (isspace(*ptr))
		    ptr++;
		curr->default_if_none = strdup(ptr);
	    } else if (!strncmp(buff, "LOC:", 4)) {
		if ((ptr = strtok(buff + 4, WS)) == NULL) {
		    printf("Error on line %d\n", linenum);
