
void Adaptation::Icap::Xaction::fillPendingStatus(MemBuf &buf) const
{
    if (connection->isOpen()) {
        buf.Printf("FD %d", connection->fd);

        if (writer != NULL)
            buf.append("w", 1);
