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
                xfree(line->data);
                xfree(line);
            }

            blank = 1;
        }

        if (entry->nocomment && blank)
            fprintf(fp, "#\n");

        for (line = entry->nocomment; line != NULL; line = line->next) {
            if (!enabled && line->data[0] != '#')
                fprintf(fp, "#%s\n", line->data);
            else
                fprintf(fp, "%s\n", line->data);
        }

        if (entry->doc != NULL) {
            fprintf(fp, "\n");
        }
    }