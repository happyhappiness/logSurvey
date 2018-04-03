void Adaptation::Icap::ModXact::prepEchoing()
{
    disableRepeats("preparing to echo content");
    disableBypass("preparing to echo content");
    setOutcome(xoEcho);

    // We want to clone the HTTP message, but we do not want
    // to copy some non-HTTP state parts that HttpMsg kids carry in them.
    // Thus, we cannot use a smart pointer, copy constructor, or equivalent.
    // Instead, we simply write the HTTP message and "clone" it by parsing.

    HttpMsg *oldHead = virgin.header;
    debugs(93, 7, HERE << "cloning virgin message " << oldHead);
