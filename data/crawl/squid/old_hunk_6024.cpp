	for (line = entry->doc; line != NULL; line = line->next) {
	    fprintf(fp, "#%s\n", line->data);
	}
	if (entry->default_value && strcmp(entry->default_value,"none") != 0) {
	    sprintf(buf, "%s %s", entry->name, entry->default_value);
	    lineAdd(&def, buf);
	}
