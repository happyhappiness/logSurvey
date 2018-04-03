}

void
ServerStateData::handleAdaptedHeader(HttpMsg *msg)
{
    if (abortOnBadEntry("entry went bad while waiting for adapted headers")) {
        // If the adapted response has a body, the ICAP side needs to know
