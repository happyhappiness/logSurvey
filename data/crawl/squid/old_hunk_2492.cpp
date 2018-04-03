            continue;

        if (entry->loc == NULL) {
            fprintf(stderr, "NO LOCATION FOR %s\n", entry->name);
            rc |= 1;
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
    fprintf(fp, "}\n\n");
    return rc;
}

static void
gen_default_if_none(Entry * head, FILE * fp)
{
    Entry *entry;
    Line *line;
    fprintf(fp,
            "static void\n"
            "defaults_if_none(void)\n"
            "{\n"
           );

    for (entry = head; entry != NULL; entry = entry->next) {
        assert(entry->name);
