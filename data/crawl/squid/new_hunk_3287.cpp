        if ( rc != SASL_OK ) {
#if SASL_VERSION_MAJOR < 2
            if ( errstr ) {
                debug("errstr %s\n", errstr);
            }
            if ( rc != SASL_BADAUTH ) {
                debug("ERROR: %d %s\n", rc, sasl_errstring(rc, NULL, NULL));
                SEND_ERR(sasl_errstring(rc, NULL, NULL));
            } else
#endif
                SEND_ERR("");
        } else {
            SEND_OK("");
        }
    }

    sasl_dispose(&conn);
    sasl_done();
    return 0;
}
