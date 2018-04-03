void Adaptation::Icap::Xaction::noteInitiatorAborted()
{

    if (theInitiator) {
        clearInitiator();
        mustStop("initiator aborted");
    }
