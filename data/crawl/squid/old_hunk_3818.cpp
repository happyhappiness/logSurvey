        reuseConnection = false; // be conservative
        cancelRead(); // may not work; and we cannot stop connecting either
        if (!doneWithIo())
            debugs(93, 7, "Warning: bypass failed to stop I/O" << status());
    }
}

void ICAPModXact::disableBypass(const char *reason)
{
    if (canStartBypass) {
        debugs(93,7, HERE << "will never start bypass because " << reason);
