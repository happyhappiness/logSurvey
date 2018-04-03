    }

    // adjust
    if ( ! isatty(fileno(stdout)) || (::debugFlag & 0x01) ) ::iamalive = false;
    if ( head == 0 ) {
        fputs( "There was no regular expression defined. If you intend\n", stderr );
        fputs( "to match all possible URLs, use \"-e .\" instead.\n", stderr );
