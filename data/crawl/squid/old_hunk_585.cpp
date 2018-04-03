// premature end of the adapted response body
void Client::handleAdaptedBodyProducerAborted()
{
    stopConsumingFrom(adaptedBodySource);
    handleAdaptationAborted();
}

// common part of noteAdaptationAnswer and handleAdaptedBodyProductionEnded
