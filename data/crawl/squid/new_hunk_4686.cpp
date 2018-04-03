void ICAPServiceRep::noteFailure() {
    ++theSessionFailures;
    debugs(93,4, "ICAPService failure " << theSessionFailures <<
        ", out of " << TheICAPConfig.service_failure_limit << " allowed");

    if (TheICAPConfig.service_failure_limit >= 0 &&
        theSessionFailures > TheICAPConfig.service_failure_limit)
        suspend("too many failures");

    // TODO: Should bypass setting affect how much Squid tries to talk to
