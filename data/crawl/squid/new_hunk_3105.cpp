
    /* maybe append Connection: keep-alive */
    if (flags.keepalive) {
        hdr_out->putStr(HDR_CONNECTION, "keep-alive");
    }

    /* append Front-End-Https */
