            continue;
        }

        if (entry->default_value == NULL && entry->default_if_none == NULL) {
            fprintf(stderr, "NO DEFAULT FOR %s\n", entry->name);
            rc |= 1;
            continue;
        }

        if (entry->default_value == NULL || strcmp(entry->default_value, "none") == 0) {
            fprintf(fp, "\t/* No default for %s */\n", entry->name);
        } else {
            if (entry->ifdef)
                fprintf(fp, "#if %s\n", entry->ifdef);

            fprintf(fp, "\tdefault_line(\"%s %s\");\n",
                    entry->name,
                    entry->default_value);

            if (entry->ifdef)
                fprintf(fp, "#endif\n");
        }
    }

    fprintf(fp, "\tcfg_filename = NULL;\n");