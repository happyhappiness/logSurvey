	"{\n"
	);
    for (entry = head; entry != NULL; entry = entry->next) {
	if (entry->loc == NULL) {
	    fprintf(fp, "\tfree_%s();\n", entry->type);
	} else {
	    fprintf(fp, "\tfree_%s(&%s);\n", entry->type, entry->loc);
	}
    }
    fprintf(fp, "}\n\n");
}