
void ICAPXaction::mustStop(const char *aReason)
{
    Must(inCall); // otherwise nobody will call doStop()
    Must(aReason);
    if (!stopReason) {
        stopReason = aReason;
