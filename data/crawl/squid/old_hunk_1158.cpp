        return;
    }

    if (hlp->stats.queue_size < (int)hlp->childs.n_running)
        return;

    if (hlp->stats.queue_size > (int)hlp->childs.n_running * 2)
        fatalf("Too many queued %s requests", hlp->id_name);

    if (squid_curtime - hlp->last_queue_warn < 600)
        return;

