		    printf("Error on line %d\n", linenum);
		    exit(1);
		}
		curr->type = xstrdup(ptr);
	    } else if (!strncmp(buff, "IFDEF:", 6)) {
		if ((ptr = strtok(buff + 6, WS)) == NULL) {
