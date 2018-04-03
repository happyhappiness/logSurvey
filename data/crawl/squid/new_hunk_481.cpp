}

void
ConnStateData::afterClientWrite(size_t size)
{
    if (pipeline.empty())
        return;

    pipeline.front()->writeComplete(size);
}

// TODO: make this only need size parameter, ConnStateData handles the rest
void
ClientSocketContext::writeComplete(size_t size)
{
    const StoreEntry *entry = http->storeEntry();
    debugs(33, 5, clientConnection << ", sz " << size <<
           ", off " << (http->out.size + size) << ", len " <<
           (entry ? entry->objectLen() : 0));

    http->out.size += size;
    clientUpdateSocketStats(http->logType, size);

    if (clientHttpRequestStatus(clientConnection->fd, http)) {
        initiateClose("failure or true request status");
        /* Do we leak here ? */
        return;
