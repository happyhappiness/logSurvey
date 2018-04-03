void
Ftp::Server::handleEpsvReply(const HttpReply *reply, StoreIOBuffer)
{
    if (pipeline.front()->http->request->errType != ERR_NONE) {
        writeCustomReply(502, "Cannot connect to server", reply);
        return;
    }
