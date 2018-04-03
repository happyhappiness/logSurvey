{
    stopProducingFor(virginBodyDestination, false);

    // do not force closeServer here in case we need to bypass IcapQueryAbort

    if (doneWithIcap()) // we may still be receiving adapted response
        handleIcapCompleted();
}

// received adapted response headers (body may follow)
void
ServerStateData::noteIcapAnswer(HttpMsg *msg)
{
    clearIcap(adaptedHeadSource); // we do not expect more messages

    if (abortOnBadEntry("entry went bad while waiting for adapted headers"))
        return;
