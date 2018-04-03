
void ICAPOptXact::makeRequest(MemBuf &buf)
{
    const Adaptation::Service &s = service();
    buf.Printf("OPTIONS %s ICAP/1.0\r\n", s.cfg().uri.buf());
    buf.Printf("Host: %s:%d\r\n", s.cfg().host.buf(), s.cfg().port);
    buf.append(ICAP::crlf, 2);
}
