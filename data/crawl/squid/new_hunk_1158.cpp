        return;
    }

    if (hlp->stats.queue_size < (int)hlp->childs.queue_size)
        return;

    if (squid_curtime - hlp->last_queue_warn < 600)
        return;

