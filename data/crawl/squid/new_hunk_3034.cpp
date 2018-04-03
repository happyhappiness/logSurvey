    return true;
}

bool
HttpStateData::getMoreRequestBody(MemBuf &buf)
{
    // parent's implementation can handle the no-encoding case
    if (!request->header.chunked())
        return ServerStateData::getMoreRequestBody(buf);

    MemBuf raw;

    Must(requestBodySource != NULL);
    if (!requestBodySource->getMoreData(raw))
        return false; // no request body bytes to chunk yet

    // optimization: pre-allocate buffer size that should be enough
    const mb_size_t rawDataSize = raw.contentSize();
    // we may need to send: hex-chunk-size CRLF raw-data CRLF last-chunk
    buf.init(16 + 2 + rawDataSize + 2 + 5, raw.max_capacity);

    buf.Printf("%"PRIX64"\r\n", rawDataSize);
    buf.append(raw.content(), rawDataSize);
    buf.Printf("\r\n");

    Must(rawDataSize > 0); // we did not accidently created last-chunk above

    // Do not send last-chunk unless we successfully received everything
    if (receivedWholeRequestBody) {
        Must(!flags.sentLastChunk);
        flags.sentLastChunk = true;
        buf.append("0\r\n\r\n", 5);    
    }

    return true;
}

void
httpStart(FwdState *fwd)
{
