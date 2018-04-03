    gen_conf(entries, fp);
    fclose(fp);

    return (rc);
}

static int
gen_default(Entry * head, FILE * fp)
{
    Entry *entry;
    int rc = 0;
    fprintf(fp,
	"void\n"
	"default_all(void)\n"
