{
    stopProducingFor(virginBodyDestination, false);

    // do not force closeServer here in case we need to bypass AdaptationQueryAbort

    if (doneWithAdaptation()) // we may still be receiving adapted response
        handleAdaptationCompleted();
}

// received adapted response headers (body may follow)
void
ServerStateData::noteAdaptationAnswer(HttpMsg *msg)
{
    clearAdaptation(adaptedHeadSource); // we do not expect more messages

    if (abortOnBadEntry("entry went bad while waiting for adapted headers"))
        return;
