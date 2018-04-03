    return rc;
}

static void
gen_default_if_none(Entry * head, FILE * fp)
{
    Entry *entry;
    fprintf(fp,
	"void\n"
	"defaults_if_none(void)\n"
	"{\n"
	);
    for (entry = head; entry != NULL; entry = entry->next) {
	assert(entry->name);
	assert(entry->loc);
	if (entry->default_if_none == NULL)
	    continue;
	fprintf(fp,
	    "\tif (check_null_%s(%s))\n"
	    "\t\tdefault_line(\"%s %s\");\n",
	    entry->type,
	    entry->loc,
	    entry->name,
	    entry->default_if_none);
    }
    fprintf(fp, "}\n\n");
}

static void
gen_parse(Entry * head, FILE * fp)
{
