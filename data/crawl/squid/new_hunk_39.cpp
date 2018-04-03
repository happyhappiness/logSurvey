        request->flags.isRanged = false;
    }

    hdr_out->addVia(request->http_ver, hdr_in);

    if (request->flags.accelerated) {
        /* Append Surrogate-Capabilities */