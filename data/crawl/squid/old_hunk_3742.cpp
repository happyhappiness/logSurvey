    mustStop("ICAP service connection externally closed");
}

void Adaptation::Icap::Xaction::callEnd()
{
    if (doneWithIo()) {
