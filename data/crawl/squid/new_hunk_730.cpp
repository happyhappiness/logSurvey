void Adaptation::Icap::Xaction::fillDoneStatus(MemBuf &buf) const
{
    if (haveConnection() && commEof)
        buf.appendf("Comm(%d)", connection->fd);

    if (stopReason != NULL)
        buf.append("Stopped", 7);
}

bool Adaptation::Icap::Xaction::fillVirginHttpHeader(MemBuf &) const
