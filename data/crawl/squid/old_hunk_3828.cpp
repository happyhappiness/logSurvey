}

// unexpected connection close while talking to the ICAP service
void ICAPXaction::noteCommClosed(const CommCloseCbParams &io)
{
    closer = NULL;
    handleCommClosed();
}

void ICAPXaction::handleCommClosed()
{
    mustStop("ICAP service connection externally closed");
}

void ICAPXaction::callEnd()
{
    if (doneWithIo()) {
        debugs(93, 5, HERE << typeName << " done with I/O" << status());
