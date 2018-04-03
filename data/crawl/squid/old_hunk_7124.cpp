
	fprintf(fp, "#  TAG: %s", entry->name);
	if (entry->comment)
		fprintf(fp, "\t%s", entry->comment);
	fprintf(fp, "\n");
	for (line = entry->doc; line != NULL; line = line->next) {
	    fprintf(fp, "#%s\n", line->data);
