    ICAPXaction_Exit();
}

// HTTP side is aborting
void ICAPModXact::noteSourceAbort(MsgPipe *p)
{
    ICAPXaction_Enter(noteSourceAbort);

    Must(!state.doneReceiving);
    stopReceiving();
    mustStop("HTTP source quit");

    ICAPXaction_Exit();
}

// HTTP side wants more adapted data and possibly freed some buffer space
void ICAPModXact::noteSinkNeed(MsgPipe *p)
{
    ICAPXaction_Enter(noteSinkNeed);

    if (state.sending == State::sendingVirgin)
        echoMore();
