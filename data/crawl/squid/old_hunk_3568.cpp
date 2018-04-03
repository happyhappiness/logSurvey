            lineAdd(&def, "none");

        if (verbose_output && def && (entry->doc || entry->nocomment)) {
	    fprintf(fp, "#Default:\n");
            while (def != NULL) {
                line = def;
                def = line->next;
