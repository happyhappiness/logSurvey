        }
    } else {
        /* ASCII/OEM string */
        sc = (char *) packet + o;

        for (; l; l--) {
            if (*sc == '\0' || !xisprint(*sc)) {
                fprintf(stderr, "ntlmssp: bad ascii: %04x\n", *sc);
                return rv;
