	    "\t} else if (!strcmp(token, \"%s\")) {\n",
	    entry->name
	    );
	if (entry->loc == NULL) {
	    fprintf(fp,
		"\t\tparse_%s();\n",
		entry->type
