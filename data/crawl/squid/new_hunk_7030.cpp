	assert(entry->loc);
	if (strcmp(entry->loc, "none") == 0)
	    continue;
	if (strcmp(entry->name, "arbtext") == 0)
	    continue;
	fprintf(fp, "\tfree_%s(&%s);\n", entry->type, entry->loc);
    }
    fprintf(fp, "}\n\n");
