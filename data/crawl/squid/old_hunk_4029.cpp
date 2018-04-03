
    const size_t sizeMax = virginContentSize(virginBodySending);
    debugs(93,5, HERE << "will echo up to " << sizeMax << " bytes from " <<
        virgin.body_pipe->status());
    debugs(93,5, HERE << "will echo up to " << sizeMax << " bytes to   " <<
        adapted.body_pipe->status());

    if (sizeMax > 0) {
        const size_t size = adapted.body_pipe->putMoreData(virginContentData(virginBodySending), sizeMax);
        debugs(93,5, HERE << "echoed " << size << " out of " << sizeMax <<
           " bytes");
        virginBodySending.progress(size);
        virginConsume();
        disableBypass("echoed content");
