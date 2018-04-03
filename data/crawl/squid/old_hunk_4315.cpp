}


// common part of noteIcap*Aborted and noteBodyConsumerAborted methods
void
ServerStateData::handleIcapAborted(bool bypassable)
{
    debugs(11,5, HERE << "handleIcapAborted; bypassable: " << bypassable <<
        ", entry empty: " << entry->isEmpty());

    if (abortOnBadEntry("entry went bad while ICAP aborted"))
