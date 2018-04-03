	if (entry->comment)
	    fprintf(fp, "\t%s", entry->comment);
	fprintf(fp, "\n");
	if (!defined(entry->ifdef)) {
	    fprintf(fp, "# Note: This option is only available if Squid is rebuilt with the\n");
	    fprintf(fp, "#       %s option\n#\n", available_if(entry->ifdef));
	}
	for (line = entry->doc; line != NULL; line = line->next) {
	    fprintf(fp, "#%s\n", line->data);
	}
	if (entry->default_value && strcmp(entry->default_value,"none") != 0) {
	    sprintf(buf, "%s %s", entry->name, entry->default_value);
	    lineAdd(&def, buf);
	}
	if (entry->default_if_none) {
	    for (line = entry->default_if_none; line; line = line->next) {
		sprintf(buf, "%s %s", entry->name, line->data);
		lineAdd(&def, buf);
	    }
	}
	if (entry->nocomment)
	    blank = 0;
	if (!def && entry->doc && !entry->nocomment &&
		strcmp(entry->name, "comment") != 0)
	    lineAdd(&def, "none");
	if (def && (entry->doc || entry->nocomment)) {
	    if (blank)
		fprintf(fp, "#\n");
	    fprintf(fp, "#Default:\n");
	    while (def != NULL) {
		line = def;
		def = line->next;
		fprintf(fp, "# %s\n", line->data);
		free(line->data);
		free(line);
	    }
	    blank=1;
	}
	if (entry->nocomment && blank)
	    fprintf(fp, "#\n");
	for (line = entry->nocomment; line != NULL; line = line->next) {
	    fprintf(fp, "%s\n", line->data);
	}
