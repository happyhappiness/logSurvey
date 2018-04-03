        virginSendClaim.protectAll();
    }

    buf.append(ICAP::crlf, 2); // terminate ICAP header

    // start ICAP request body with encapsulated HTTP headers
