
void Adaptation::Icap::Xaction::fillDoneStatus(MemBuf &buf) const
{
    if (connection->isOpen() && commEof)
        buf.Printf("Comm(%d)", connection->fd);

    if (stopReason != NULL)
        buf.Printf("Stopped");
