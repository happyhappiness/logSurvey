    fprintf(fp, "}\n\n");
}

static void
gen_conf(Entry * head, FILE * fp)
{
    Entry *entry;

    for (entry = head; entry != NULL; entry = entry->next) {
	Line *line;

	if (!strcmp(entry->name, "comment"))
	    (void) 0;
