            continue;

        if (entry->ifdef)
            fprintf(fp, "#if %s\n", entry->ifdef);

        if (entry->default_if_none) {
            fprintf(fp,
                    "\tif (check_null_%s(%s)) {\n",
                    entry->type,
                    entry->loc);

            for (line = entry->default_if_none; line; line = line->next)
                fprintf(fp,
                        "\t\tdefault_line(\"%s %s\");\n",
                        entry->name,
                        line->data);

            fprintf(fp, "\t}\n");
        }

        if (entry->ifdef)
            fprintf(fp, "#endif\n");
    }

    fprintf(fp, "}\n\n");
}

void
gen_parse_alias(char *name, EntryAlias *alias, Entry *entry, FILE *fp)
{
    fprintf(fp, "\tif (!strcmp(token, \"%s\")) {\n", name);

    if (strcmp(entry->type,"obsolete") == 0) {
        fprintf(fp, "\t\tdebugs(0, DBG_CRITICAL, \"ERROR: Directive '%s' is obsolete.\");\n", name);
        for (Line *line = entry->doc; line != NULL; line = line->next) {
            // offset line to strip initial whitespace tab byte
            fprintf(fp, "\t\tdebugs(0, opt_parse_cfg_only?0:1, \"%s : %s\");\n", name, &line->data[1]);
        }
        fprintf(fp, "\t\tparse_obsolete(token);\n");
    } else if (!entry->loc || strcmp(entry->loc, "none") == 0) {
        fprintf(fp,
                "\t\tparse_%s();\n",
                entry->type
               );
    } else {
        fprintf(fp,
                "\t\tparse_%s(&%s%s);\n",
                entry->type, entry->loc,
                entry->array_flag ? "[0]" : ""
               );
    }

    fprintf(fp,"\t\treturn 1;\n");
    fprintf(fp,"\t};\n");
}

void
gen_parse_entry(Entry *entry, FILE *fp)
{
    if (strcmp(entry->name, "comment") == 0)
        return;

    if (entry->ifdef)
        fprintf(fp, "#if %s\n", entry->ifdef);

    char *name = entry->name;

