    entry->buffer();
    reply->setHeaders(Http::scOkay, "Gatewaying", mime_type, -1, -1, -2);
    if (mime_enc)
        reply->header.putStr(Http::HdrType::CONTENT_ENCODING, mime_enc);

    entry->replaceHttpReply(reply);
}
