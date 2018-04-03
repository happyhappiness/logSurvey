    if (!flags.http_header_sent && data.readBuf->contentSize() >= 0)
        appendSuccessHeader();

#if ICAP_CLIENT

    if (icapAccessCheckPending) {