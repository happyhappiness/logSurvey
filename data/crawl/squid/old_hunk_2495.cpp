            continue;

        if (entry->ifdef)
            fprintf(fp, "#if %s\n", entry->ifdef);

        fprintf(fp, "\tdump_%s(entry, \"%s\", %s);\n",
                entry->type,
                entry->name,
                entry->loc);

        if (entry->ifdef)
            fprintf(fp, "#endif\n");
    }

    fprintf(fp, "}\n\n");
}

static void
gen_free(Entry * head, FILE * fp)
{
    Entry *entry;
    fprintf(fp,
            "static void\n"
            "free_all(void)\n"
            "{\n"
            "    debugs(5, 4, HERE);\n"
           );

    for (entry = head; entry != NULL; entry = entry->next) {
        if (!entry->loc || strcmp(entry->loc, "none") == 0)
