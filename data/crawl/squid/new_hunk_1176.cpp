
// more adapted response body is available
void
Client::handleMoreAdaptedBodyAvailable()
{
    if (abortOnBadEntry("entry refuses adapted body"))
        return;
