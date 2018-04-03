    if (mime_enc)
        reply->header.putStr(Http::HdrType::CONTENT_ENCODING, mime_enc);

    setVirginReply(reply);
    adaptOrFinalizeReply();
}
