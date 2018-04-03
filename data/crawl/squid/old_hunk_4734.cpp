void ICAPServiceRep::noteNewOptions(ICAPOptXact *x)
{
    Must(x);
    Must(waiting());

    theState = stateDown; // default in case we fail to set new options

    changeOptions(x->options);
    x->options = NULL;
    delete x;

    if (theOptions && theOptions->valid())
        theState = stateUp;

    debugs(93,6, "ICAPService got new options and is now " <<
           (up() ? "up" : "down"));

    scheduleUpdate();

    scheduleNotification();
}

void ICAPServiceRep::startGettingOptions()
{
    debugs(93,6, "ICAPService will get new options " << status());
    theState = stateWait;

    ICAPOptXact *x = new ICAPOptXact;
    x->start(self, &ICAPServiceRep_noteNewOptions, this);
    // TODO: timeout incase ICAPOptXact never calls us back?
}

void ICAPServiceRep::scheduleUpdate()
{
    int delay = -1;

    if (theOptions && theOptions->valid()) {
        const time_t expire = theOptions->expire();

        if (expire > squid_curtime)
            delay = expire - squid_curtime;
        else
            if (expire >= 0)
                delay = 1; // delay for expired or 'expiring now' options
            else
                delay = 60*60; // default for options w/o known expiration time
    } else {
        delay = 5*60; // delay for a down service
    }

    if (delay <= 0) {
        debugs(93,0, "internal error: ICAPServiceRep failed to compute options update schedule");
        delay = 5*60; // delay for an internal error
    }

    // with zero delay, the state changes to stateWait before
    // notifications are sent out to clients
    assert(delay > 0);

    debugs(93,7, "ICAPService will update options in " << delay << " sec");

    eventAdd("ICAPServiceRep::noteTimeToUpdate",
             &ICAPServiceRep_noteTimeToUpdate, this, delay, 0, true);

    // XXX: prompt updates of valid options should not disable concurrent ICAP
    // xactions. 'Wait' state should not mark the service 'down'! This will
    // also remove 'delay == 0' as a special case above.
}

const char *ICAPServiceRep::status() const
{
    if (!self)
        return "[invalidated]";

    switch (theState) {

    case stateInit:
        return "[init]";

    case stateWait:
        return "[wait]";

    case stateUp:
        return "[up]";

    case stateDown:
        return "[down]";
    }

    return "[unknown]";
}
