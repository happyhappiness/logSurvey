void ICAPModXact::moveRequestChunk(MemBuf &buf, size_t chunkSize)
{
    if (chunkSize > 0) {
        openChunk(buf, chunkSize);
        buf.append(claimContent(virginWriteClaim), chunkSize);
        closeChunk(buf, false);

        virginWriteClaim.release(chunkSize);
        virginConsume();
    }

    if (state.writing == State::writingPreview)
        preview.wrote(chunkSize, state.doneReceiving); // even if wrote nothing
}

void ICAPModXact::addLastRequestChunk(MemBuf &buf)
{
    openChunk(buf, 0);
    closeChunk(buf, state.writing == State::writingPreview && preview.ieof());
}

void ICAPModXact::openChunk(MemBuf &buf, size_t chunkSize)
{
    buf.Printf("%x\r\n", (int) chunkSize);
}

void ICAPModXact::closeChunk(MemBuf &buf, bool ieof)
{
    if (ieof)
        buf.append("; ieof", 6);

    buf.append(ICAP::crlf, 2); // chunk-terminating CRLF
}

