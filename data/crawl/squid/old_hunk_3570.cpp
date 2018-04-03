    exit(1);
}

int
main(int argc, char *argv[])
{
    FILE *fp;
    char *input_filename = argv[1];
    const char *output_filename = _PATH_PARSER;
    const char *conf_filename = _PATH_SQUID_CONF;
    const char *type_depend = argv[2];
    int linenum = 0;
    Entry *entries = NULL;
    Entry *curr = NULL;
