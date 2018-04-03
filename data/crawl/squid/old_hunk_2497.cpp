        else if (!strcmp(entry->name, "obsolete"))
            (void) 0;
        else if (verbose_output) {
            fprintf(fp, "#  TAG: %s", entry->name);

            if (entry->comment)
                fprintf(fp, "\t%s", entry->comment);

            fprintf(fp, "\n");
        }

        if (!defined(entry->ifdef)) {
            if (verbose_output) {
                fprintf(fp, "# Note: This option is only available if Squid is rebuilt with the\n");
                fprintf(fp, "#       %s\n#\n", available_if(entry->ifdef));
            }
            enabled = 0;
        }

        if (verbose_output) {
            for (line = entry->doc; line != NULL; line = line->next) {
                fprintf(fp, "#%s\n", line->data);
            }
        }

