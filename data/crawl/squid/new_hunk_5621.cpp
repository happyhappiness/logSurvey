	    continue;
	if (entry->ifdef)
	    fprintf(fp, "#if %s\n", entry->ifdef);
	name = entry->name;
	alias = entry->alias;
next_alias:
	fprintf(fp, "\telse if (!strcmp(token, \"%s\"))\n", name);
	assert(entry->loc);
	if (strcmp(entry->loc, "none") == 0) {
	    fprintf(fp,
