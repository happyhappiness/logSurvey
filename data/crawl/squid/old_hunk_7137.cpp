	"{\n"
	);
    for (entry = head; entry != NULL; entry = entry->next) {
	if (entry->loc == NULL) {
	    fprintf(fp, "\tprintf(\"%s = \");\n", entry->type);
	    fprintf(fp, "\tdump_%s();\n", entry->type);
	} else {
	    fprintf(fp, "\tprintf(\"%s = \");\n", entry->loc);
	    fprintf(fp, "\tdump_%s(%s);\n", entry->type, entry->loc);
	}
	fprintf(fp, "\tprintf(\"\\n\");\n");
	fprintf(fp, "\n");
    }
    fprintf(fp, "}\n\n");
}
