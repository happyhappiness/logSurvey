// We actually start sending (echoig or not) in startSending.
void Adaptation::Icap::ModXact::prepEchoing()
{
    disableBypass("preparing to echo content");

    // We want to clone the HTTP message, but we do not want
    // to copy some non-HTTP state parts that HttpMsg kids carry in them.
