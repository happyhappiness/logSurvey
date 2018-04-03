        }

        /* Set no-cache if determined needed but not found */
        if (orig_request->flags.nocache && !hdr_in->has(HDR_PRAGMA))
            EBIT_SET(cc->mask, CC_NO_CACHE);

        /* Enforce sibling relations */
        if (flags.only_if_cached)
            EBIT_SET(cc->mask, CC_ONLY_IF_CACHED);

        hdr_out->putCc(cc);

        httpHdrCcDestroy(cc);
    }

    /* maybe append Connection: keep-alive */
    if (flags.keepalive) {
        if (flags.proxying) {
            hdr_out->putStr(HDR_PROXY_CONNECTION, "keep-alive");
        } else {
            hdr_out->putStr(HDR_CONNECTION, "keep-alive");
        }
    }

    /* append Front-End-Https */
    if (flags.front_end_https) {
        if (flags.front_end_https == 1 || request->protocol == PROTO_HTTPS)
            hdr_out->putStr(HDR_FRONT_END_HTTPS, "On");
    }

    /* Now mangle the headers. */
