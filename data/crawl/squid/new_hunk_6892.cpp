	    continue;
	}
	assert(entry->default_value);
	if (entry->ifdef)
	    fprintf(fp, "#ifdef %s\n", entry->ifdef);
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
    fprintf(fp, "}\n\n");
