void ICAPOptXact::makeRequest(MemBuf &buf)
{
    const ICAPServiceRep &s = service();
    buf.Printf("OPTIONS %s ICAP/1.0\r\n", s.uri.buf());
    buf.Printf("Host: %s:%d\r\n", s.host.buf(), s.port);
    buf.append(ICAP::crlf, 2);
}

