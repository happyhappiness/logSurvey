
// received adapted response headers (body may follow)
void
ServerStateData::noteIcapAnswer(HttpMsg *msg)
{
    HttpReply *rep = dynamic_cast<HttpReply*>(msg);
    HTTPMSGLOCK(rep);
    clearIcap(adaptedHeadSource); // we do not expect more messages

    if (abortOnBadEntry("entry went bad while waiting for adapted headers")) {
        HTTPMSGUNLOCK(rep); // hopefully still safe, even if "this" is deleted
