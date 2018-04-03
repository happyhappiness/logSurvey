gen_parse(Entry * head, FILE * fp)
{
    Entry *entry;
    char *name;
    EntryAlias *alias;

    fprintf(fp,
	"static int\n"
