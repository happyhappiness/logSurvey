static void
clientPackTermBound(String boundary, MemBuf * mb)
{
    mb->Printf("\r\n--%s--\r\n", boundary.unsafeBuf());
    debugs(33, 6, "clientPackTermBound: buf offset: " << mb->size);
}

