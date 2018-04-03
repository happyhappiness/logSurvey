
    assert(connRegistered_);
    connRegistered_ = false;
    conn->pipeline.popMe(Http::StreamPointer(this));
}

/// called when we encounter a response-related error
void
Http::Stream::initiateClose(const char *reason)
{
    debugs(33, 4, clientConnection << " because " << reason);
    getConn()->stopSending(reason); // closes ASAP
}

void
Http::Stream::deferRecipientForLater(clientStreamNode *node, HttpReply *rep, StoreIOBuffer receivedData)
{
    debugs(33, 2, "Deferring request " << http->uri);
    assert(flags.deferred == 0);
