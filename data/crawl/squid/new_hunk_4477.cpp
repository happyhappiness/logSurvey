            fprintf(fp, "#\n");

        for (line = entry->nocomment; line != NULL; line = line->next) {
	    if (!enabled && line->data[0] != '#')
		fprintf(fp, "#%s\n", line->data);
	    else
		fprintf(fp, "%s\n", line->data);
        }

        if (entry->doc != NULL) {