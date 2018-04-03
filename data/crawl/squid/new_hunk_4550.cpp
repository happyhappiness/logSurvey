        parseBody();
}

void ICAPModXact::callException(const TextException &e)
{
    if (!canStartBypass || isRetriable) {
        ICAPXaction::callException(e);
        return;
    }

    try {
        debugs(93, 2, "bypassing ICAPModXact::" << inCall << " exception: " <<
           e.message << ' ' << status());
        bypassFailure();
    }
    catch (const TextException &bypassE) {
        ICAPXaction::callException(bypassE);
    }
}

void ICAPModXact::bypassFailure()
{
    disableBypass("already started to bypass");

    Must(!isRetriable); // or we should not be bypassing

    prepEchoing();

    startSending();

    // end all activities associated with the ICAP server

    stopParsing();

    stopWriting(true); // or should we force it?
    if (connection >= 0) {
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
        canStartBypass = false;
    }
}



// note that allocation for echoing is done in handle204NoContent()
void ICAPModXact::maybeAllocateHttpMsg()
{
