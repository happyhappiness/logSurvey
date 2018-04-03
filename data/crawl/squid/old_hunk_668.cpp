    }
};

long
Security::ParseOptions(const char *options)
{
    long op = 0;
    char *tmp;
    char *option;

    if (options) {

    tmp = xstrdup(options);
    option = strtok(tmp, ":,");

    while (option) {

        enum {
            MODE_ADD, MODE_REMOVE
        } mode;

        switch (*option) {

        case '!':

        case '-':
            mode = MODE_REMOVE;
            ++option;
            break;

        case '+':
            mode = MODE_ADD;
            ++option;
            break;

        default:
            mode = MODE_ADD;
            break;
        }

        struct ssl_option *opt = NULL;
        for (struct ssl_option *opttmp = ssl_options; opttmp->name; ++opttmp) {
            if (strcmp(opttmp->name, option) == 0) {
                opt = opttmp;
                break;
            }
        }

        long value = 0;
        if (opt)
            value = opt->value;
        else if (strncmp(option, "0x", 2) == 0) {
            /* Special case.. hex specification */
            value = strtol(option + 2, NULL, 16);
        } else {
            fatalf("Unknown TLS option '%s'", option);
            value = 0;      /* Keep GCC happy */
        }

        switch (mode) {
