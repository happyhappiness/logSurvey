        }
        sslFlags = SBuf(token + 6);
        parsedFlags = parseFlags();
    } else if (strncmp(token, "no-default-ca", 13) == 0) {
        flags.tlsDefaultCa = false;
    } else if (strncmp(token, "domain=", 7) == 0) {
        sslDomain = SBuf(token + 7);
    } else if (strncmp(token, "no-npn", 6) == 0) {
