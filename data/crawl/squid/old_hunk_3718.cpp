void Adaptation::Icap::ModXact::startSending()
{
    disableRepeats("sent headers");
    disableBypass("sent headers");
    sendAnswer(adapted.header);

    if (state.sending == State::sendingVirgin)
