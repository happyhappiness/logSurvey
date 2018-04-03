        if ( rc != SASL_OK ) {
#if SASL_VERSION_MAJOR < 2
            if ( errstr ) {
                fprintf( stderr, "errstr %s\n", errstr );
            }
            if ( rc != SASL_BADAUTH ) {
                fprintf( stderr, "error %d %s\n", rc, sasl_errstring(rc, NULL, NULL ));
            }
#endif
            fprintf( stdout, "ERR\n" );
        } else {
            fprintf( stdout, "OK\n" );
        }

    }

    sasl_dispose( &conn );
    sasl_done();

    return 0;
}
