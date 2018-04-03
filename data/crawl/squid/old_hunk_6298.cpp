	if (strcmp(entry->name, "comment") == 0)
	    continue;
	if (entry->ifdef)
	    fprintf(fp, "#ifdef %s\n", entry->ifdef);
	fprintf(fp, "\tfree_%s(&%s);\n", entry->type, entry->loc);
	if (entry->ifdef)
	    fprintf(fp, "#endif\n");