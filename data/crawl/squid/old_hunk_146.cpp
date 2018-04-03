    else
        Enqueue(this, r);

    if (!queueFull()) {
        full_time = 0;
    } else if (!full_time) {
        debugs(84, 3, id_name << " queue became full");
        full_time = squid_curtime;
    }
}

void
helperSubmit(helper * hlp, const char *buf, HLPCB * callback, void *data)
{
    if (hlp == NULL) {
        debugs(84, 3, "helperSubmit: hlp == NULL");
        Helper::Reply const nilReply(Helper::Unknown);
        callback(data, nilReply);
        return;
    }
    hlp->prepSubmit();
    hlp->submit(buf, callback, data);
}

bool
helper::queueFull() const {
    return stats.queue_size > static_cast<int>(childs.queue_size);
}

/// prepares the helper for request submission via trySubmit() or helperSubmit()
/// currently maintains full_time and kills Squid if the helper remains full for too long
void
helper::prepSubmit()
{
    if (!queueFull())
        full_time = 0;
    else if (!full_time) // may happen here if reconfigure decreases capacity
        full_time = squid_curtime;
    else if (squid_curtime - full_time > 180)
        fatalf("Too many queued %s requests", id_name);
}

bool
helper::trySubmit(const char *buf, HLPCB * callback, void *data)
{
    prepSubmit();

    if (queueFull()) {
        debugs(84, DBG_IMPORTANT, id_name << " drops request due to a full queue");
        return false; // request was ignored
    }

    submit(buf, callback, data); // will send or queue
    return true; // request submitted or queued
