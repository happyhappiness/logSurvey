            continue;

        if (entry->loc == NULL) {
            std::cerr << "NO LOCATION FOR " << entry->name << std::endl;
            rc |= 1;
            continue;
        }

        if (entry->default_value == NULL && entry->default_if_none == NULL) {
            std::cerr << "NO DEFAULT FOR " << entry->name << std::endl;
            rc |= 1;
            continue;
        }

        if (entry->default_value == NULL || strcmp(entry->default_value, "none") == 0) {
            fout << "\t/* No default for " << entry->name << " */\n";
        } else {
            if (entry->ifdef)
                fout << "#if " << entry->ifdef << std::endl;

            fout << "\tdefault_line(\"" << entry->name << " " << 
                entry->default_value << "\");\n";

            if (entry->ifdef)
                fout << "#endif\n"; }
    }

    fout << "\tcfg_filename = NULL;\n"
        "}\n\n";
    return rc;
}

static void
gen_default_if_none(Entry * head, std::ostream &fout)
{
    Entry *entry;
    Line *line;
    fout << "static void\n"
            "defaults_if_none(void)\n"
            "{\n";

    for (entry = head; entry != NULL; entry = entry->next) {
        assert(entry->name);
