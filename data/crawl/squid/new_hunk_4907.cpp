
void ICAPModXact::openChunk(MemBuf &buf, size_t chunkSize)
{
    buf.Printf("%x\r\n", (int) chunkSize);
}

void ICAPModXact::closeChunk(MemBuf &buf, bool ieof)
