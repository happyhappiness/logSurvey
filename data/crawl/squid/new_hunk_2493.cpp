            continue;

        if (entry->ifdef)
            fout << "#if " << entry->ifdef << std::endl;

        if (entry->default_if_none) {
            fout << "\tif (check_null_" << entry->type << "(" <<
                entry->loc << ")) {\n";

            for (line = entry->default_if_none; line; line = line->next)
                fout << "\t\tdefault_line(\"" << entry->name << " " <<
                    line->data <<"\");\n";

            fout << "\t}\n";
        }

        if (entry->ifdef)
            fout << "#endif\n";
    }

    fout << "}\n\n";
}

void
gen_parse_alias(char *name, EntryAlias *alias, Entry *entry, std::ostream &fout)
{
    fout << "\tif (!strcmp(token, \"" << name << "\")) {\n";

    if (strcmp(entry->type,"obsolete") == 0) {
        fout << "\t\tdebugs(0, DBG_CRITICAL, \"ERROR: Directive '" << name << "' is obsolete.\");\n";
        for (Line *line = entry->doc; line != NULL; line = line->next) {
            // offset line to strip initial whitespace tab byte
            fout << "\t\tdebugs(0, opt_parse_cfg_only?0:1, \"" << name << " : " << &line->data[1] << "\");\n";
        }
        fout << "\t\tparse_obsolete(token);\n";
    } else if (!entry->loc || strcmp(entry->loc, "none") == 0) {
        fout << "\t\tparse_" << entry->type << "();\n";
    } else {
        fout << "\t\tparse_" << entry->type << "(&" << entry->loc <<
            (entry->array_flag ? "[0]" : "") << ");\n";
    }

    fout << "\t\treturn 1;\n";
    fout << "\t};\n";
}

void
gen_parse_entry(Entry *entry, std::ostream &fout)
{
    if (strcmp(entry->name, "comment") == 0)
        return;

    if (entry->ifdef)
        fout << "#if " << entry->ifdef << std::endl;

    char *name = entry->name;

