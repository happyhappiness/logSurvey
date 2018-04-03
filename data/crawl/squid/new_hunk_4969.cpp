static void
clientPackTermBound(String boundary, MemBuf * mb)
{
    mb->Printf("\r\n--%s--\r\n", boundary.buf());
    debug(33, 6) ("clientPackTermBound: buf offset: %ld\n", (long int) mb->size);
}

