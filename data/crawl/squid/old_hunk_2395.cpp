void
ServerStateData::handleAdaptedBodyProductionEnded()
{
    stopConsumingFrom(adaptedBodySource);

    if (abortOnBadEntry("entry went bad while waiting for adapted body eof"))
        return;

    handleAdaptationCompleted();
}

