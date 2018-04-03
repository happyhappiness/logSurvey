    exit(1);
}

static void
usage(const char *program_name)
{
    fprintf(stderr, "Usage: %s cf.data cf.data.depend\n", program_name);
    exit(1);
}

int
main(int argc, char *argv[])
{
    FILE *fp;
    char *input_filename;
    const char *output_filename = _PATH_PARSER;
    const char *conf_filename = _PATH_SQUID_CONF;
    const char *conf_filename_short = _PATH_SQUID_CONF_SHORT;
    const char *type_depend;
    int linenum = 0;
    Entry *entries = NULL;
    Entry *curr = NULL;
