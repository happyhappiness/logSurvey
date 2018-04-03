    return false;
}

Adaptation::AccessCheck::AccessCheck(const ServiceFilter &aFilter,
                                     AccessCheckCallback *aCallback,
                                     void *aCallbackData):
    AsyncJob("AccessCheck"), filter(aFilter),
    callback(aCallback),
    callback_data(cbdataReference(aCallbackData)),
    acl_checklist(NULL)
{
#if ICAP_CLIENT
    Adaptation::Icap::History::Pointer h = filter.request->icapHistory();
    if (h != NULL)
        h->start("ACL");
#endif

    debugs(93, 5, HERE << "AccessCheck constructed for " <<
        methodStr(filter.method) << " " << vectPointStr(filter.point));
}

Adaptation::AccessCheck::~AccessCheck()
{
#if ICAP_CLIENT
    Adaptation::Icap::History::Pointer h = filter.request->icapHistory();
    if (h != NULL)
        h->stop("ACL");
#endif
    if (callback_data)
        cbdataReferenceDone(callback_data);
}

/// Walk the access rules list to find rules with applicable service groups
void
Adaptation::AccessCheck::check()
{
    debugs(93, 4, HERE << "start checking");

    typedef AccessRules::iterator ARI;
    for (ARI i = AllRules().begin(); i != AllRules().end(); ++i) {
        AccessRule *r = *i;
        if (isCandidate(*r)) {
            debugs(93, 5, HERE << "check: rule '" << r->id << "' is a candidate");
            candidates += r->id;
        }
    }
