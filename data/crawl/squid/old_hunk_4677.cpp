}

// HTTP side sent us all virgin info
void ICAPModXact::noteSourceFinish(MsgPipe *p)
{
    ICAPXaction_Enter(noteSourceFinish);

    Must(!state.doneReceiving);
    stopReceiving();

    // push writer and sender in case we were waiting for the last-chunk
    writeMore();
