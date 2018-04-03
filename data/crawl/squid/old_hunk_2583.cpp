void
ServerStateData::handleAdaptedHeader(HttpMsg *msg)
{
    if (abortOnBadEntry("entry went bad while waiting for adapted headers"))
        return;

    HttpReply *rep = dynamic_cast<HttpReply*>(msg);
    assert(rep);
