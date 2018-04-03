    // TODO: it would be nice to invalidate cbdata(this) when not destroyed
}

void ICAPServiceRep::noteFailure()
{
    ++theSessionFailures;
    debugs(93,4, theSessionFailures << " ICAPService failures, out of " <<
           TheICAPConfig.service_failure_limit << " allowed " << status());

    if (isSuspended)
        return;

    if (TheICAPConfig.service_failure_limit >= 0 &&
            theSessionFailures > TheICAPConfig.service_failure_limit)
        suspend("too many failures");

    // TODO: Should bypass setting affect how much Squid tries to talk to
