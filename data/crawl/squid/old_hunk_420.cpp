}

void
ClientSocketContext::doClose()
{
    clientConnection->close();
}

/// called when we encounter a response-related error
void
ClientSocketContext::initiateClose(const char *reason)
{
    debugs(33, 4, clientConnection << " because " << reason);
    http->getConn()->stopSending(reason); // closes ASAP
