    // should be configurable.
}

void ICAPServiceRep::suspend(const char *reason)
{
    if (isSuspended) {
        debugs(93,4, "keeping ICAPService suspended, also for " << reason);
    } else {
        isSuspended = reason;
        debugs(93,1, "suspending ICAPService for " << reason);
        scheduleUpdate(squid_curtime + TheICAPConfig.service_revival_delay);
        announceStatusChange("suspended", true);
    }
}

bool ICAPServiceRep::probed() const
{
    return theLastUpdate != 0;
}

bool ICAPServiceRep::hasOptions() const
{
    return theOptions && theOptions->valid() && theOptions->fresh();
}

bool ICAPServiceRep::up() const
{
    return self != NULL && !isSuspended && hasOptions();
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


static
void ICAPServiceRep_noteTimeToUpdate(void *data)
{
    ICAPServiceRep *service = static_cast<ICAPServiceRep*>(data);
    Must(service);
    service->noteTimeToUpdate();
}

void ICAPServiceRep::noteTimeToUpdate()
{
    if (self != NULL)
        updateScheduled = false;

    if (!self || theOptionsFetcher) {
        debugs(93,5, "ICAPService ignores options update " << status());
        return;
    }

    debugs(93,5, "ICAPService performs a regular options update " << status());
    startGettingOptions();
}

#if 0
static
void ICAPServiceRep_noteTimeToNotify(void *data)
{
    ICAPServiceRep *service = static_cast<ICAPServiceRep*>(data);
    Must(service);
    service->noteTimeToNotify();
}
#endif

void ICAPServiceRep::noteTimeToNotify()
{
    Must(!notifying);
    notifying = true;
    debugs(93,7, "ICAPService notifies " << theClients.size() << " clients " <<
           status());

    // note: we must notify even if we are invalidated
