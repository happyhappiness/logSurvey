void ICAPServiceRep::noteNewOptions(ICAPOptXact *x)
{
    Must(x);
    Must(waiting);
    waiting = false;

    changeOptions(x->options);
    x->options = NULL;
    delete x;

    debugs(93,3, "ICAPService got new options and is now " << status());

    scheduleUpdate();
    scheduleNotification();
}

void ICAPServiceRep::startGettingOptions()
{
    Must(!waiting);
    debugs(93,6, "ICAPService will get new options " << status());
    waiting = true;

    ICAPOptXact *x = new ICAPOptXact;
    x->start(self, &ICAPServiceRep_noteNewOptions, this);
    // TODO: timeout in case ICAPOptXact never calls us back?
}

void ICAPServiceRep::scheduleUpdate()
{
    if (updateScheduled)
        return; // already scheduled

    // XXX: move hard-coded constants from here to TheICAPConfig

    // conservative estimate of how long the OPTIONS transaction will take
    const int expectedWait = 20; // seconds

    time_t when = 0;

    if (theOptions && theOptions->valid()) {
        const time_t expire = theOptions->expire();
        debugs(93,7, "ICAPService options expire on " << expire << " >= " << squid_curtime);

        if (expire < 0) // unknown expiration time
            when = squid_curtime + 60*60;
        else
        if (expire < expectedWait) // invalid expiration time
            when = squid_curtime + 60*60;
        else
            when = expire - expectedWait; // before the current options expire
    } else {
        when = squid_curtime + 3*60; // delay for a down service
    }

    debugs(93,7, "ICAPService options raw update on " << when << " or " << (when - squid_curtime));
    if (when < squid_curtime)
        when = squid_curtime;

    const int minUpdateGap = 1*60; // seconds
    if (when < theLastUpdate + minUpdateGap)
        when = theLastUpdate + minUpdateGap;

    // TODO: keep the time of the last update to prevet too-frequent updates

    const int delay = when - squid_curtime;

    debugs(93,5, "ICAPService will update options in " << delay << " sec");

    eventAdd("ICAPServiceRep::noteTimeToUpdate",
             &ICAPServiceRep_noteTimeToUpdate, this, delay, 0, true);
    updateScheduled = true;
}

// returns a temporary string depicting service status, for debugging
const char *ICAPServiceRep::status() const
{
    static MemBuf buf;

    buf.reset();
    buf.append("[", 1);

    if (up())
        buf.append("up", 2);
    else
        buf.append("down", 4);

    if (!self)
        buf.append(",gone", 5);

    if (waiting)
        buf.append(",wait", 5);

    if (notifying)
        buf.append(",notif", 6);

    if (theSessionFailures > 0)
        buf.Printf(",F%d", theSessionFailures);

    if (isSuspended)
        buf.append(",susp", 5);

    buf.append("]", 1);
    buf.terminate();

    return buf.content();
}
