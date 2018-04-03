    xfree(sbuf);
}

void
Ftp::Gateway::processReplyBody()
{
    debugs(9, 3, status());

    if (request->method == Http::METHOD_HEAD && (flags.isdir || theSize != -1)) {
        serverComplete();
