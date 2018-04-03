    icapReply = new HttpReply;
    icapReply->protoPrefix = "ICAP/"; // TODO: make an IcapReply class?

    // XXX: make sure stop() cleans all buffers
}

// HTTP side starts sending virgin data
void ICAPModXact::noteSourceStart(MsgPipe *p)
{
    ICAPXaction_Enter(noteSourceStart);

    // make sure TheBackupLimit is in-sync with the buffer size
    Must(TheBackupLimit <= static_cast<size_t>(virgin->data->body->max_capacity));

    estimateVirginBody(); // before virgin disappears!

