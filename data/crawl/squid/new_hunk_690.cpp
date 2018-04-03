    return srv->data;
}

void
helper::packStatsInto(Packable *p, const char *label) const
{
    if (label)
        p->appendf("%s:\n", label);

    p->appendf("  program: %s\n", cmdline->key);
    p->appendf("  number active: %d of %d (%d shutting down)\n", childs.n_active, childs.n_max, (childs.n_running - childs.n_active));
    p->appendf("  requests sent: %d\n", stats.requests);
    p->appendf("  replies received: %d\n", stats.replies);
    p->appendf("  requests timedout: %d\n", stats.timedout);
    p->appendf("  queue length: %d\n", stats.queue_size);
    p->appendf("  avg service time: %d msec\n", stats.avg_svc_time);
    p->append("\n",1);
    p->appendf("%7s\t%7s\t%7s\t%11s\t%11s\t%11s\t%6s\t%7s\t%7s\t%7s\n",
                      "ID #",
                      "FD",
                      "PID",
