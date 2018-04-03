	"{\n"
	);
    for (entry = head; entry != NULL; entry = entry->next) {
	assert(entry->loc);
	if (strcmp(entry->loc, "none") == 0)
	    continue;
	fprintf(fp, "\tprintf(\"%s = \");\n", entry->loc);
	fprintf(fp, "\tdump_%s(%s);\n", entry->type, entry->loc);
	fprintf(fp, "\tprintf(\"\\n\");\n");
    }
    fprintf(fp, "}\n\n");
}
