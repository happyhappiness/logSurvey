    fprintf(fp, "}\n\n");
}

static int defined(char *name)
{
	int i=0;
	if (!name)
	    return 1;
	for(i=0;strcmp(defines[i].name, name) != 0; i++) {
	    assert(defines[i].name);
	}
	return defines[i].defined;
}

static const char *available_if(char *name)
{
	int i=0;
	assert(name);
	for(i=0;strcmp(defines[i].name, name) != 0; i++) {
	    assert(defines[i].name);
	}
	return defines[i].enable;
}

static void
gen_conf(Entry * head, FILE * fp)
{
    Entry *entry;
    char buf[8192];
    Line *def = NULL;

    for (entry = head; entry != NULL; entry = entry->next) {
	Line *line;
	int blank = 1;

	if (!strcmp(entry->name, "comment"))
	    (void) 0;
