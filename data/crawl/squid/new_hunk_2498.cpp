            lineAdd(&def, "none");

        if (verbose_output && def && (entry->doc || entry->nocomment)) {
            fout << "#Default:\n";
            while (def != NULL) {
                line = def;
                def = line->next;
                fout << "# " << line->data << std::endl;
                xfree(line->data);
                xfree(line);
            }
        }

        if (verbose_output && entry->nocomment)
            fout << "#" << std::endl;

        if (enabled || verbose_output) {
            for (line = entry->nocomment; line != NULL; line = line->next) {
                if (!line->data)
                    continue;
                if (!enabled && line->data[0] != '#')
                    fout << "#" << line->data << std::endl;
                else
                    fout << line->data << std::endl;
            }
        }

        if (verbose_output && entry->doc != NULL) {
            fout << std::endl;
        }
    }
}