void ICAPServiceRep::noteFailure() {
    ++theSessionFailures;
    debugs(93,4, "ICAPService failure " << theSessionFailures <<
        ", out of " << TheSessionFailureLimit << " allowed");

    if (theSessionFailures > TheSessionFailureLimit)
        suspend("too many failures");

    // TODO: Should bypass setting affect how much Squid tries to talk to
