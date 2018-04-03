                      "Offset",
                      "Request");

    for (dlink_node *link = servers.head; link; link = link->next) {
        HelperServerBase *srv = static_cast<HelperServerBase *>(link->data);
        assert(srv);
        Helper::Request *request = srv->requests.empty() ? NULL : srv->requests.front();
        double tt = 0.001 * (request ? tvSubMsec(request->dispatch_time, current_time) : tvSubMsec(srv->dispatch_time, srv->answer_time));
        p->appendf("%7u\t%7d\t%7d\t%11" PRIu64 "\t%11" PRIu64 "\t%11" PRIu64 "\t%c%c%c%c%c%c\t%7.3f\t%7d\t%s\n",
                          srv->index.value,
                          srv->readPipe->fd,
                          srv->pid,
