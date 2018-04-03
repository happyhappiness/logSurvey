            continue;

        if (entry->ifdef)
            fout << "#if " << entry->ifdef << std::endl;

        fout << "\tdump_" << entry->type << "(entry, \"" << entry->name <<
            "\", " << entry->loc << ");\n";

        if (entry->ifdef)
            fout << "#endif\n";
    }

    fout << "}\n\n";
}

static void
gen_free(Entry * head, std::ostream &fout)
{
    Entry *entry;
    fout <<
            "static void\n"
            "free_all(void)\n"
            "{\n"
            "    debugs(5, 4, HERE);\n";

    for (entry = head; entry != NULL; entry = entry->next) {
        if (!entry->loc || strcmp(entry->loc, "none") == 0)
