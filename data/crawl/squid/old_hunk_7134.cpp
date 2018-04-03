    gen_conf(entries, fp);
    fclose(fp);

    return (0);
}

static void
gen_default(Entry * head, FILE * fp)
{
    Entry *entry;
    fprintf(fp,
	"void\n"
	"default_all(void)\n"
