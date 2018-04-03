
    acl_checklist = NULL;

#if ICAP_CLIENT
    Adaptation::Icap::History::Pointer h = req->icapHistory();
    if (h != NULL)
        h->start("ACL");
#endif

    debugs(93, 5, HERE << "AccessCheck constructed for " << methodStr(method) << " " << vectPointStr(point));
}

Adaptation::AccessCheck::~AccessCheck()
{
#if ICAP_CLIENT
    Adaptation::Icap::History::Pointer h = req->icapHistory();
    if (h != NULL)
        h->stop("ACL");
#endif
    HTTPMSGUNLOCK(req);
    HTTPMSGUNLOCK(rep);
    if (callback_data)
