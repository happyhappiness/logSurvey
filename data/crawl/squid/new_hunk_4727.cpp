void ICAPModXact::moveRequestChunk(MemBuf &buf, size_t chunkSize)
{
    if (chunkSize > 0) {
        openChunk(buf, chunkSize, false);
        buf.append(claimContent(virginWriteClaim), chunkSize);
        closeChunk(buf);

        virginWriteClaim.release(chunkSize);
        virginConsume();
    }

    if (state.writing == State::writingPreview) {
        // even if we are doneReceiving, we may not have written everything
        const bool wroteEof = state.doneReceiving &&
            claimSize(virginWriteClaim) <= 0;
        preview.wrote(chunkSize, wroteEof); // even if wrote nothing
    }
}

void ICAPModXact::addLastRequestChunk(MemBuf &buf)
{
    const bool ieof = state.writing == State::writingPreview && preview.ieof();
    openChunk(buf, 0, ieof);
    closeChunk(buf);
}

void ICAPModXact::openChunk(MemBuf &buf, size_t chunkSize, bool ieof)
{
    buf.Printf((ieof ? "%x; ieof\r\n" : "%x\r\n"), (int) chunkSize);
}

void ICAPModXact::closeChunk(MemBuf &buf)
{
    buf.append(ICAP::crlf, 2); // chunk-terminating CRLF
}

