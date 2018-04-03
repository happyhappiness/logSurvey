    if (TheICAPConfig.send_client_username && request)
        makeUsernameHeader(request, buf);

    // fprintf(stderr, "%s\n", unsafeBuf.content());

    buf.append(ICAP::crlf, 2); // terminate ICAP header

