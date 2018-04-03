            encapsulateHead(buf, "res-hdr", httpBuf, prime);

    if (!virginBody.expected())
        buf.Printf("null-body=%d", httpBuf.contentSize());
    else if (ICAP::methodReqmod == m)
        buf.Printf("req-body=%d", httpBuf.contentSize());
    else
        buf.Printf("res-body=%d", httpBuf.contentSize());

    buf.append(ICAP::crlf, 2); // terminate Encapsulated line

