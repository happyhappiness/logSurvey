{
    Entry *entry;
    int rc = 0;
    fprintf(fp,
	"void\n"
	"default_line(const char *s)\n"
	"{\n"
	"\tLOCAL_ARRAY(char, tmp_line, BUFSIZ);\n"
        "\txstrncpy(tmp_line, s, BUFSIZ);\n"
        "\txstrncpy(config_input_line, s, BUFSIZ);\n"
	"\tconfig_lineno++;\n"
        "\tparse_line(tmp_line);\n"
	"}\n"
	);

    fprintf(fp,
	"void\n"
	"default_all(void)\n"
	"{\n"
	"\tcfg_filename = \"Default Configuration\";\n"
	"\tconfig_lineno = 0;\n"
	);
    for (entry = head; entry != NULL; entry = entry->next) {
	assert(entry->name);
