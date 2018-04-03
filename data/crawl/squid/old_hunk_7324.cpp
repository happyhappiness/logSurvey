    p->last_fail_time = squid_curtime;
    eventAdd("peerCheckConnect", peerCheckConnect, p, 80);
}
