            continue;
        }

        if (entry->default_value == NULL) {
            fprintf(stderr, "NO DEFAULT FOR %s\n", entry->name);
            rc |= 1;
            continue;
        }

        assert(entry->default_value);

        if (entry->ifdef)
            fprintf(fp, "#if %s\n", entry->ifdef);

        if (strcmp(entry->default_value, "none") == 0) {
            fprintf(fp, "\t/* No default for %s */\n", entry->name);
        } else {
            fprintf(fp, "\tdefault_line(\"%s %s\");\n",
                    entry->name,
                    entry->default_value);
        }

        if (entry->ifdef)
            fprintf(fp, "#endif\n");
    }

    fprintf(fp, "\tcfg_filename = NULL;\n");