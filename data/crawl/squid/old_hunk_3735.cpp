// called after parsing all headers or when bypassing an exception
void Adaptation::Icap::ModXact::startSending()
{
    disableBypass("sent headers");
    sendAnswer(adapted.header);

