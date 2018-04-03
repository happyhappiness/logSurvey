
void ICAPXaction::handleCommTimedout()
{
    debugs(93, 0, HERE << "ICAP FD " << connection << " timeout to " << theService->methodStr() << " " << theService->uri.buf());
    reuseConnection = false;
    MemBuf mb;
    mb.init();

    if (fillVirginHttpHeader(mb)) {
        debugs(93, 0, HERE << "\tfor " << mb.content());
    }

    mustStop("connection with ICAP service timed out");
}

// unexpected connection close while talking to the ICAP service
