    const String host = s.cfg().host;
    buf.Printf("Host: " SQUIDSTRINGPH ":%d\r\n", SQUIDSTRINGPRINT(host), s.cfg().port);
    buf.append(ICAP::crlf, 2);

    // XXX: HttpRequest cannot fully parse ICAP Request-Line
    http_status status;
    Must(icapRequest->parse(&buf, true, &status) > 0);
}

void Adaptation::Icap::OptXact::handleCommWrote(size_t size)
