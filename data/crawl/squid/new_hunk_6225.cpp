    for (entry = head; entry != NULL; entry = entry->next) {
	Line *line;

	if (!strcmp(entry->name, "comment"))
	    (void) 0;
	else
	    fprintf(fp, "#  TAG: %s", entry->name);
	if (entry->comment)
	    fprintf(fp, "\t%s", entry->comment);
	fprintf(fp, "\n");
	for (line = entry->doc; line != NULL; line = line->next) {
	    fprintf(fp, "#%s\n", line->data);
	}
	for (line = entry->nocomment; line != NULL; line = line->next) {
	    fprintf(fp, "%s\n", line->data);
	}
	if (entry->doc != NULL) {
	    fprintf(fp, "\n");
	}
