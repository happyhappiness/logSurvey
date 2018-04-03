    }

    // prepare regular expression for matching
    if ( debug ) fprintf( debug, "# trying to compile \"%s\"\n", expression );
    regex_t rexp;
    int result = regcomp( &rexp, expression, REG_EXTENDED );
    if ( result != 0 ) {
        char buffer[256];
        regerror( result, &rexp, buffer, sizeof(buffer) );
        fprintf( stderr, "regular expression \"%s\": %s\n", expression, buffer );
        return -1;
    }

    // read line by line
    if ( debug ) fputs( "# trying to read lines\n", debug );

    regmatch_t subs[8];
    char *s, line[1024];
    CacheDir cd;
    while ( cfgin.getline( line, sizeof(line)) ) {
