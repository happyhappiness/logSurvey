        reuseConnection = false; // be conservative
        cancelRead(); // may not work; and we cannot stop connecting either
        if (!doneWithIo())
            debugs(93, 7, HERE << "Warning: bypass failed to stop I/O" << status());
    }
}

void Adaptation::Icap::ModXact::disableBypass(const char *reason)
{
    if (canStartBypass) {
        debugs(93,7, HERE << "will never start bypass because " << reason);
