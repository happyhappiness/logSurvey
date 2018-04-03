    }

    // adjust
    if ( ! isatty(fileno(stdout)) || (::debug & 0x01) ) ::iamalive = false;
    if ( head == 0 ) {
        fputs( "There was no regular expression defined. If you intend\n", stderr );
        fputs( "to match all possible URLs, use \"-e .\" instead.\n", stderr );
