{
    // setup variables
    REList* list = 0;
    char* conffile = xstrdup( DEFAULT_SQUID_CONF );
    serverPort = htons(DEFAULTPORT);
    if ( convertHostname(DEFAULTHOST,serverHost) == -1 ) {
        fprintf( stderr, "unable to resolve host %s!\n", DEFAULTHOST );
