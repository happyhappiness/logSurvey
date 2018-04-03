    Entry *entry;
    fprintf(fp,
	"void\n"
	"dump_config(StoreEntry *entry)\n"
	"{\n"
	);
    for (entry = head; entry != NULL; entry = entry->next) {
	assert(entry->loc);
	if (strcmp(entry->loc, "none") == 0)
	    continue;
	fprintf(fp, "\tdump_%s(entry, \"%s\", %s);\n",
		entry->type,
		entry->name,
		entry->loc);
    }
    fprintf(fp, "}\n\n");
}
