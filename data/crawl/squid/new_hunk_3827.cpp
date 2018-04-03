    // should be configurable.
}

void Adaptation::Icap::ServiceRep::suspend(const char *reason)
{
    if (isSuspended) {
        debugs(93,4, HERE << "keeping suspended, also for " << reason);
    } else {
        isSuspended = reason;
        debugs(93,1, "suspending ICAP service for " << reason);
        scheduleUpdate(squid_curtime + TheConfig.service_revival_delay);
        announceStatusChange("suspended", true);
    }
}

bool Adaptation::Icap::ServiceRep::probed() const
{
    return theLastUpdate != 0;
}

bool Adaptation::Icap::ServiceRep::hasOptions() const
{
    return theOptions && theOptions->valid() && theOptions->fresh();
}

bool Adaptation::Icap::ServiceRep::up() const
{
    return self != NULL && !isSuspended && hasOptions();
}

bool Adaptation::Icap::ServiceRep::wantsUrl(const String &urlPath) const
{
    Must(hasOptions());
    return theOptions->transferKind(urlPath) != Adaptation::Icap::Options::xferIgnore;
}

bool Adaptation::Icap::ServiceRep::wantsPreview(const String &urlPath, size_t &wantedSize) const
{
    Must(hasOptions());

    if (theOptions->preview < 0)
        return false;

    if (theOptions->transferKind(urlPath) != Adaptation::Icap::Options::xferPreview)
        return false;

    wantedSize = theOptions->preview;

    return true;
}

bool Adaptation::Icap::ServiceRep::allows204() const
{
    Must(hasOptions());
    return true; // in the future, we may have ACLs to prevent 204s
}


static
void ServiceRep_noteTimeToUpdate(void *data)
{
    Adaptation::Icap::ServiceRep *service = static_cast<Adaptation::Icap::ServiceRep*>(data);
    Must(service);
    service->noteTimeToUpdate();
}

void Adaptation::Icap::ServiceRep::noteTimeToUpdate()
{
    if (self != NULL)
        updateScheduled = false;

    if (!self || theOptionsFetcher) {
        debugs(93,5, HERE << "ignores options update " << status());
        return;
    }

    debugs(93,5, HERE << "performs a regular options update " << status());
    startGettingOptions();
}

#if 0
static
void Adaptation::Icap::ServiceRep_noteTimeToNotify(void *data)
{
    Adaptation::Icap::ServiceRep *service = static_cast<Adaptation::Icap::ServiceRep*>(data);
    Must(service);
    service->noteTimeToNotify();
}
#endif

void Adaptation::Icap::ServiceRep::noteTimeToNotify()
{
    Must(!notifying);
    notifying = true;
    debugs(93,7, HERE << "notifies " << theClients.size() << " clients " <<
           status());

    // note: we must notify even if we are invalidated
