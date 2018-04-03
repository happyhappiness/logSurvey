{
    char cfgline[2048];
    char cfgparam[2048];
    snprintf(cfgline, 2048, "%s", s);

    // Keep the initial value on cfgparam. The ConfigParser  methods will write on cfgline
    strncpy(cfgparam, cfgline, sizeof(cfgparam)-1);
    cfgparam[sizeof(cfgparam)-1] = '\0';

    // Initialize parser to point to the start of quoted string
    ConfigParser::SetCfgLine(cfgline);
    String unEscaped = ConfigParser::NextToken();

    const bool interpOk = (unEscaped.cmp(expectInterp) == 0);
    if (!interpOk) {
