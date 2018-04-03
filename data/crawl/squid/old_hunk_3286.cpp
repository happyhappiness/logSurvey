#endif

    if ( rc != SASL_OK ) {
        fprintf( stderr, "error %d %s\n", rc, sasl_errstring(rc, NULL, NULL ));
        fprintf( stdout, "ERR\n" );
        return 1;
    }

    while ( fgets( line, sizeof( line ), stdin )) {
        username = &line[0];
        password = strchr( line, '\n' );
        if ( !password) {
            fprintf( stderr, "authenticator: Unexpected input '%s'\n", line );
            fprintf( stdout, "ERR\n" );
            continue;
        }
        *password = '\0';
        password = strchr ( line, ' ' );
        if ( !password) {
            fprintf( stderr, "authenticator: Unexpected input '%s'\n", line );
            fprintf( stdout, "ERR\n" );
            continue;
        }
        *password++ = '\0';
