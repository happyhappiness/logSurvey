        }
    } else {
        /* ASCII/OEM string */
        char *sc = rv.str;

        for (; l>=0; sc++, l--) {
            if (*sc == '\0' || !xisprint(*sc)) {
                fprintf(stderr, "ntlmssp: bad ascii: %04x\n", *sc);
                return rv;
