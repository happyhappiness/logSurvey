        else if (!strcmp(entry->name, "obsolete"))
            (void) 0;
        else if (verbose_output) {
            fout << "#  TAG: " << entry->name;

            if (entry->comment)
                fout << "\t" << entry->comment;

            fout << std::endl;
        }

        if (!defined(entry->ifdef)) {
            if (verbose_output) {

                fout << "# Note: This option is only available if "
                    "Squid is rebuilt with the\n" <<
                    "#       " << available_if(entry->ifdef) << "\n#\n";
            }
            enabled = 0;
        }

        if (verbose_output) {
            for (line = entry->doc; line != NULL; line = line->next) {
                fout << "#" << line->data << std::endl;
            }
        }

