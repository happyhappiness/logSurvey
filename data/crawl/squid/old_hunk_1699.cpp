{
    char cfgline[2048];
    char cfgparam[2048];
    snprintf(cfgline, 2048, "Config %s", s);

    // Points to the start of quoted string
    const char *tmp = strchr(cfgline, ' ');

    if (tmp == NULL) {
        fprintf(stderr, "Invalid config line: %s\n", s);
        return false;
    }

    // Keep the initial value on cfgparam. The ConfigParser  methods will write on cfgline
    strncpy(cfgparam, tmp+1, sizeof(cfgparam)-1);
    cfgparam[sizeof(cfgparam)-1] = '\0';

    // Initialize parser to point to the start of quoted string
    strtok(cfgline, w_space);
    String unEscaped;
    ConfigParser::ParseQuotedString(&unEscaped);

    const bool interpOk = (unEscaped.cmp(expectInterp) == 0);
    if (!interpOk) {
