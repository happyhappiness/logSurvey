    ac->noteAnswer(answer==ACCESS_ALLOWED);
}

void
Adaptation::AccessCheck::noteAnswer(int answer)
{
    debugs(93, 5, HERE << "AccessCheck::noteAnswer " << answer);
    if (candidates.size())
        debugs(93, 5, HERE << "was checking rule" << topCandidate());

    if (!answer) {
        candidates.shift(); // the rule did not match
        checkCandidates();
        return;
    }

    /*
     * We use an event here to break deep function call sequences
     */
    // XXX: use AsyncCall for callback and remove
    CallJobHere(93, 5, this, Adaptation::AccessCheck::do_callback);
}

void
Adaptation::AccessCheck::do_callback()
{
    debugs(93, 3, HERE);

    if (candidates.size())
        debugs(93, 3, HERE << "was checking rule" << topCandidate());

    void *validated_cbdata;
    if (!cbdataReferenceValidDone(callback_data, &validated_cbdata)) {
        debugs(93,3,HERE << "do_callback: callback_data became invalid, skipping");
        return;
    }

    ServicePointer service = NULL;
    if (candidates.size()) {
        if (AccessRule *r = FindRule(topCandidate())) {
            service = findBestService(*r, true);
            if (service != NULL)
                debugs(93,3,HERE << "do_callback: with service " << service->cfg().uri);
            else
                debugs(93,3,HERE << "do_callback: no service for rule" << r->id);
        } else {
            debugs(93,3,HERE << "do_callback: no rule" << topCandidate());
        }
        candidates.shift(); // done with topCandidate()
    } else {
        debugs(93,3,HERE << "do_callback: no candidate rules");
    }

    callback(service, validated_cbdata);
    done = TRUE;
}

Adaptation::ServicePointer
Adaptation::AccessCheck::findBestService(AccessRule &r, bool preferUp)
{

    const char *what = preferUp ? "up " : "";
    debugs(93,7,HERE << "looking for the first matching " <<
           what << "service in group " << r.groupId);

    ServicePointer secondBest;

    ServiceGroup *g = FindGroup(r.groupId);

    if (!g) {
        debugs(93,5,HERE << "lost " << r.groupId << " group in rule" << r.id);
        return ServicePointer();
    }

    ServiceGroup::Loop loop(g->initialServices());
    typedef ServiceGroup::iterator SGI;
    for (SGI i = loop.begin; i != loop.end; ++i) {

        ServicePointer service = FindService(*i);

        if (!service)
            continue;

        if (method != service->cfg().method)
            continue;

        if (point != service->cfg().point)
            continue;

        // sending a message to a broken service is likely to cause errors
        if (service->cfg().bypass && service->broken())
            continue;

        if (service->up()) {
            // sending a message to a service that does not want it is useless
            // note that we cannot check wantsUrl for service that is not "up"
            // note that even essential services are skipped on unwanted URLs!
            if (!service->wantsUrl(req->urlpath))
                continue;
        } else {
            if (!secondBest)
                secondBest = service;
            if (preferUp) {
                // the caller asked for an "up" service and we can bypass this one
                if (service->cfg().bypass)
                    continue;
                debugs(93,5,HERE << "cannot skip an essential down service");
                what = "down-but-essential ";
            }
        }

        debugs(93,5,HERE << "found first matching " <<
               what << "service for " << r.groupId << " group in rule" << r.id <<
               ": " << service->cfg().key);

        return service;
    }

    if (secondBest != NULL) {
        what = "down ";
        debugs(93,5,HERE << "found first matching " <<
               what << "service for " << r.groupId << " group in rule" << r.id <<
               ": " << secondBest->cfg().key);
        return secondBest;
    }

    debugs(93,5,HERE << "found no matching " <<
           what << "services for " << r.groupId << " group in rule" << r.id);
    return ServicePointer();
}
