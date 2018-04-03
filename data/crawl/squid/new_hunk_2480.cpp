            cur++;
    }

    type = LFT_NONE;

    // Scan each token namespace
    if (strncmp(cur, "icap::", 6) == 0) {
#if ICAP_CLIENT
        cur += 6;
        debugs(46, 5, HERE << "scan for icap:: token");
        cur = scanForToken(TokenTableIcap, cur);
#else
        debugs(46, DBG_IMPORTANT, "ERROR: Format uses icap:: token. ICAP disabled!");
#endif
    } else if (strncmp(cur, "adapt::", 7) == 0) {
#if USE_ADAPTATION
        cur += 7;
        debugs(46, 5, HERE << "scan for adapt:: token");
        cur = scanForToken(TokenTableAdapt, cur);
#else
        debugs(46, DBG_IMPORTANT, "ERROR: Format uses adapt:: token. Adaptation disabled!");
#endif
    } else {
        // For upward compatibility, assume "http::" prefix as default prefix
        // for all log access formating codes, except those starting with a
        // "%" or a known namespace. (ie "icap::", "adapt::")
        if (strncmp(cur,"http::", 6) == 0 && *(cur+6) != '%' )
            cur += 6;

        // NP: scan the sets of tokens in decreasing size to guarantee no
        //     mistakes made with overlapping names. (Bug 3310)

        // Scan for various long tokens
        debugs(46, 5, HERE << "scan for possible Misc token");
        cur = scanForToken(TokenTableMisc, cur);
        // scan for 2-char tokens
        if (type == LFT_NONE) {
        debugs(46, 5, HERE << "scan for possible 2C token");
            cur = scanForToken(TokenTable2C, cur);
        }
        // finally scan for 1-char tokens.
        if (type == LFT_NONE) {
            debugs(46, 5, HERE << "scan for possible 1C token");
            cur = scanForToken(TokenTable1C, cur);
        }
    }

    if (type == LFT_NONE) {
        fatalf("Can't parse configuration token: '%s'\n", def);
    }

    if (*cur == ' ') {
