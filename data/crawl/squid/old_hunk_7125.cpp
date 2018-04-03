{
    Entry *entry;
    int rc = 0;
    fprintf(fp,
	"void\n"
	"default_all(void)\n"
	"{\n"
	"\tcfg_filename = \"Default Configuration\";\n"
	);
    for (entry = head; entry != NULL; entry = entry->next) {
	assert(entry->name);
