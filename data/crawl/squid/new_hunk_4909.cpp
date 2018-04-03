void ICAPModXact::encapsulateHead(MemBuf &icapBuf, const char *section, MemBuf &httpBuf, const HttpMsg *head)
{
    // update ICAP header
    icapBuf.Printf("%s=%d,", section, (int) httpBuf.contentSize());

    // pack HTTP head
    packHead(httpBuf, head);
