gen_default_if_none(Entry * head, FILE * fp)
{
    Entry *entry;
    Line *line;
    fprintf(fp,
	"static void\n"
	"defaults_if_none(void)\n"
