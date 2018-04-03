		ptr = buff + 16;
		while (xisspace(*ptr))
		    ptr++;
		curr->default_if_none = xstrdup(ptr);
	    } else if (!strncmp(buff, "LOC:", 4)) {
		if ((ptr = strtok(buff + 4, WS)) == NULL) {
		    printf("Error on line %d\n", linenum);
