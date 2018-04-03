
void ICAPXaction::handleCommTimedout()
{
    debugs(93, 2, HERE << typeName << " timeout with " <<
        theService->methodStr() << " " << theService->uri.buf() << status());
    reuseConnection = false;
    service().noteFailure();

    throw TexcHere(connector ?
        "timed out while connecting to the ICAP service" :
        "timed out while talking to the ICAP service");
}

// unexpected connection close while talking to the ICAP service
