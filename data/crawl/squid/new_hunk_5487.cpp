    fprintf(fp, "}\n\n");
}

void
gen_parse_alias(char *name, EntryAlias *alias, Entry *entry, FILE *fp)
{
	fprintf(fp, "\tif (!strcmp(token, \"%s\")) {\n", name);
	if (strcmp(entry->loc, "none") == 0) {
	    fprintf(fp,
		"\t\tparse_%s();\n",
