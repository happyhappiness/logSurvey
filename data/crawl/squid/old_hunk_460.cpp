void
Ftp::Server::handlePasvReply(const HttpReply *reply, StoreIOBuffer)
{
    ClientSocketContext::Pointer context = getCurrentContext();
    assert(context != NULL);

    if (context->http->request->errType != ERR_NONE) {
        writeCustomReply(502, "Server does not support PASV", reply);
