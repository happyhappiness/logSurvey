    if (abortOnBadEntry("entry went bad while waiting for adapted body eof"))
        return;

    handleIcapCompleted();
}

// premature end of the adapted response body
void ServerStateData::handleAdaptedBodyProducerAborted()
{
    stopConsumingFrom(adaptedBodySource);
    handleIcapAborted();
}

// common part of noteIcapAnswer and handleAdaptedBodyProductionEnded
void
ServerStateData::handleIcapCompleted()
{
    debugs(11,5, HERE << "handleIcapCompleted");
    cleanIcap();

    // We stop reading origin response because we have no place to put it and
    // cannot use it. If some origin servers do not like that or if we want to
