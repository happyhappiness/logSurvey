
void ICAPModXact::makeRequestHeaders(MemBuf &buf)
{
    const ICAPServiceRep &s = service();
    buf.Printf("%s %s ICAP/1.0\r\n", s.methodStr(), s.uri.buf());
    buf.Printf("Host: %s:%d\r\n", s.host.buf(), s.port);
    buf.Printf("Encapsulated: ");

    MemBuf httpBuf;
    httpBuf.init();

    // build HTTP request header, if any
