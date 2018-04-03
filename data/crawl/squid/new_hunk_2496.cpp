            continue;

        if (entry->ifdef)
            fout << "#if " << entry->ifdef << std::endl;

        fout << "\tfree_" << entry->type << "(&" << entry->loc <<
            (entry->array_flag ? "[0]" : "") << ");\n";

        if (entry->ifdef)
            fout << "#endif\n";
    }

    fout << "}\n\n";
}

static int
