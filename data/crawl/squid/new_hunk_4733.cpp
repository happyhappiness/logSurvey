void ICAPServiceRep::invalidate()
{
    assert(self != NULL);
    Pointer savedSelf = self; // to prevent destruction when we nullify self
    self = NULL;

    announceStatusChange("invalidated by reconfigure", false);

    savedSelf = NULL; // may destroy us and, hence, invalidate cbdata(this)
    // TODO: it would be nice to invalidate cbdata(this) when not destroyed
}

void ICAPServiceRep::noteFailure() {
    ++theSessionFailures;
    debugs(93,4, "ICAPService failure " << theSessionFailures <<
        ", out of " << TheSessionFailureLimit << " allowed");

    if (theSessionFailures > TheSessionFailureLimit)
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
        isSuspended = reason;
        debugs(93,1, "suspending ICAPService for " << reason);
        announceStatusChange("suspended", true);
    }
}

bool ICAPServiceRep::probed() const
{
    return theLastUpdate != 0;
}

bool ICAPServiceRep::hasOptions() const {
    return theOptions && theOptions->valid() && theOptions->fresh();
}

bool ICAPServiceRep::up() const
{
    return self != NULL && !isSuspended && hasOptions();
}

bool ICAPServiceRep::broken() const
{
    return probed() && !up();
}

bool ICAPServiceRep::wantsUrl(const String &urlPath) const
{
    Must(hasOptions());
    return theOptions->transferKind(urlPath) != ICAPOptions::xferIgnore;
}

bool ICAPServiceRep::wantsPreview(const String &urlPath, size_t &wantedSize) const
{
    Must(hasOptions());

    if (theOptions->preview < 0)
        return false;

    if (theOptions->transferKind(urlPath) != ICAPOptions::xferPreview)
        return false;

    wantedSize = theOptions->preview;

    return true;
}

bool ICAPServiceRep::allows204() const
{
    Must(hasOptions());
    return true; // in the future, we may have ACLs to prevent 204s
}

