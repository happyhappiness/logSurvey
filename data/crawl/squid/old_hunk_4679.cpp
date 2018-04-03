    ICAPXaction_Exit();
}

// HTTP side aborted
void ICAPModXact::noteSinkAbort(MsgPipe *p)
{
    ICAPXaction_Enter(noteSinkAbort);

    mustStop("HTTP sink quit");

    ICAPXaction_Exit();
}

// internal cleanup
void ICAPModXact::doStop()
{
    debugs(93, 5, HERE << "doStop() called");
    ICAPXaction::doStop();

    stopWriting(false);
    stopBackup();
