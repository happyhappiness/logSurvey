    }
};

/**
 * Pre-parse TLS options= parameter to be applied when the TLS objects created.
 * Options must not used in the case of peek or stare bump mode.
 */
long
Security::PeerOptions::parseOptions()
{
    long op = 0;
    ::Parser::Tokenizer tok(sslOptions);

    do {
        enum {
            MODE_ADD, MODE_REMOVE
        } mode;

        if (tok.skip('-') || tok.skip('!'))
            mode = MODE_REMOVE;
        else {
            (void)tok.skip('+'); // default action is add. ignore if missing operator
            mode = MODE_ADD;
        }

        static const CharacterSet optChars = CharacterSet("TLS-option", "_") + CharacterSet::ALPHA + CharacterSet::DIGIT;
        int64_t hex = 0;
        SBuf option;
        long value = 0;

        if (tok.int64(hex, 16, false)) {
            /* Special case.. hex specification */
            value = hex;
        }

        else if (tok.prefix(option, optChars)) {
            // find the named option in our supported set
            for (struct ssl_option *opttmp = ssl_options; opttmp->name; ++opttmp) {
                if (option.cmp(opttmp->name) == 0) {
                    value = opttmp->value;
                    break;
                }
            }
        }

        if (!value) {
            fatalf("Unknown TLS option '" SQUIDSBUFPH "'", SQUIDSBUFPRINT(option));
        }

        switch (mode) {
