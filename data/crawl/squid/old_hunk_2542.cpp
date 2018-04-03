
void Adaptation::Icap::Xaction::fillPendingStatus(MemBuf &buf) const
{
    if (connection >= 0) {
        buf.Printf("FD %d", connection);

        if (writer != NULL)
            buf.append("w", 1);
