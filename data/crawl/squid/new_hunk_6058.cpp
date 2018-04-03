	    continue;
	if (entry->ifdef)
	    fprintf(fp, "#if %s\n", entry->ifdef);
	if (entry->default_if_none) {
	    fprintf(fp,
		"\tif (check_null_%s(%s)) {\n",
		entry->type,
		entry->loc);
	    for (line = entry->default_if_none; line; line = line->next)
		fprintf(fp,
		    "\t\tdefault_line(\"%s %s\");\n",
		    entry->name,
		    line->data);
	    fprintf(fp, "\t}\n");
	}
	if (entry->ifdef)
	fprintf(fp, "#endif\n");
    }
    fprintf(fp, "}\n\n");
}
