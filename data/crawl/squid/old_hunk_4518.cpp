void
ServerStateData::noteIcapAnswer(HttpMsg *msg)
{
    HttpReply *rep = dynamic_cast<HttpReply*>(msg);
    HTTPMSGLOCK(rep);
    clearIcap(adaptedHeadSource); // we do not expect more messages

    if (abortOnBadEntry("entry went bad while waiting for adapted headers")) {
        HTTPMSGUNLOCK(rep); // hopefully still safe, even if "this" is deleted
        return;
    }

    assert(rep);
    entry->replaceHttpReply(rep);
    HTTPMSGUNLOCK(reply);

    reply = rep; // already HTTPMSGLOCKed above

    haveParsedReplyHeaders();

    assert(!adaptedBodySource);
    if (reply->body_pipe != NULL) {
        // subscribe to receive adapted body
        adaptedBodySource = reply->body_pipe;
        // assume that ICAP does not auto-consume on failures
        assert(adaptedBodySource->setConsumerIfNotLate(this));
    } else {
