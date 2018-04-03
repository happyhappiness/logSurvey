gen_dump(Entry * head, FILE * fp)
{
    Entry *entry;
    fprintf(fp,
	"void\n"
	"dump_all(void)\n"
	"{\n"
	);
    for (entry = head; entry != NULL; entry = entry->next) {
	if (entry->loc == NULL) {
	    fprintf(fp, "\tprintf(\"%s = \");\n", entry->type);
