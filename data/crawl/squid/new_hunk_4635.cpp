    mustStop("ICAP service connection externally closed");
}

void ICAPXaction::callEnd()
{
    if (doneWithIo()) {
        debugs(93, 5, HERE << typeName << " done with I/O" << status());
        closeConnection();
    }
    ICAPInitiate::callEnd(); // may destroy us
}

bool ICAPXaction::doneAll() const
{
    return !connector && !reader && !writer && ICAPInitiate::doneAll();
}

void ICAPXaction::updateTimeout() {
