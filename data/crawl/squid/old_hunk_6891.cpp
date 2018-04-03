		    exit(1);
		}
		curr->type = strdup(ptr);
	    } else if (!strcmp(buff, "DOC_START")) {
		state = sDOC;
	    } else if (!strcmp(buff, "DOC_NONE")) {
