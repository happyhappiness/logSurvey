
        if (!strcmp(entry->name, "comment"))
            (void) 0;
        else if (verbose_output) {
            fprintf(fp, "#  TAG: %s", entry->name);

