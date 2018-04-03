    fprintf(fp, "}\n\n");
}

static void
gen_parse(Entry * head, FILE * fp)
{
    Entry *entry;
    char *name;
    EntryAlias *alias;

    fprintf(fp,
	"static int\n"
	"parse_line(char *buff)\n"
	"{\n"
	"\tint\tresult = 1;\n"
	"\tchar\t*token;\n"
	"\tdebug(0,10)(\"parse_line: %%s\\n\", buff);\n"
	"\tif ((token = strtok(buff, w_space)) == NULL)\n"
	"\t\t(void) 0;\t/* ignore empty lines */\n"
	);

    for (entry = head; entry != NULL; entry = entry->next) {
	if (strcmp(entry->name, "comment") == 0)
	    continue;
	if (entry->ifdef)
	    fprintf(fp, "#if %s\n", entry->ifdef);
	name = entry->name;
	alias = entry->alias;
      next_alias:
	fprintf(fp, "\telse if (!strcmp(token, \"%s\"))\n", name);
	assert(entry->loc);
	if (strcmp(entry->loc, "none") == 0) {
	    fprintf(fp,
		"\t\tparse_%s();\n",
