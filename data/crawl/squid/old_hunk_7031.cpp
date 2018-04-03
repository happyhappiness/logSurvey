    for (entry = head; entry != NULL; entry = entry->next) {
	Line *line;

	fprintf(fp, "#  TAG: %s", entry->name);
	if (entry->comment)
	    fprintf(fp, "\t%s", entry->comment);
	fprintf(fp, "\n");