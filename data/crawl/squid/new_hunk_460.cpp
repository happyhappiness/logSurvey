void
Ftp::Server::handlePasvReply(const HttpReply *reply, StoreIOBuffer)
{
    const ClientSocketContext::Pointer context(pipeline.front());
    assert(context != nullptr);

    if (context->http->request->errType != ERR_NONE) {
        writeCustomReply(502, "Server does not support PASV", reply);
