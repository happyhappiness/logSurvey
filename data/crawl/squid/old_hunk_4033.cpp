    // TODO: it would be nice to invalidate cbdata(this) when not destroyed
}

void ICAPServiceRep::noteFailure() {
    ++theSessionFailures;
    debugs(93,4, theSessionFailures << " ICAPService failures, out of " << 
        TheICAPConfig.service_failure_limit << " allowed " << status());

    if (isSuspended)
        return;

    if (TheICAPConfig.service_failure_limit >= 0 &&
        theSessionFailures > TheICAPConfig.service_failure_limit)
        suspend("too many failures");

    // TODO: Should bypass setting affect how much Squid tries to talk to
    // the ICAP service that is currently unusable and is likely to remain 
    // so for some time? The current code says "no". Perhaps the answer 
    // should be configurable.
}

void ICAPServiceRep::suspend(const char *reason) {
    if (isSuspended) {
        debugs(93,4, "keeping ICAPService suspended, also for " << reason);
    } else {
