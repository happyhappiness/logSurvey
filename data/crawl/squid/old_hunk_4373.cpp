
void AsyncJob::noteStart()
{
    AsyncCallEnter(noteStart);

    start();

    AsyncCallExit();
}

void AsyncJob::start()
{
    Must(cbdataReferenceValid(this)); // locked in AsyncStart
}

void AsyncJob::mustStop(const char *aReason)
{
    Must(inCall); // otherwise nobody will delete us if we are done()
    Must(aReason);
    if (!stopReason) {
        stopReason = aReason;
