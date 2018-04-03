    (*L)->data = xstrdup(str);
}

int
main(int argc, char *argv[])
{
    FILE *fp;
    char *input_filename = argv[1];
    const char *output_filename = _PATH_PARSER;
    const char *conf_filename = _PATH_SQUID_CONF;
    int linenum = 0;
    Entry *entries = NULL;
    Entry *curr = NULL;
    enum State state;
    int rc = 0;
    char *ptr = NULL;
