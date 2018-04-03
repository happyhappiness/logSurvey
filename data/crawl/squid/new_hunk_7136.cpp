	    "\t} else if (!strcmp(token, \"%s\")) {\n",
	    entry->name
	    );
	assert(entry->loc);
	if (strcmp(entry->loc, "none") == 0) {
	    fprintf(fp,
		"\t\tparse_%s();\n",
		entry->type
