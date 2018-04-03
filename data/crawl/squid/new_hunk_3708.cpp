    ac->noteAnswer(answer==ACCESS_ALLOWED);
}

/// process the results of the ACL check
void
Adaptation::AccessCheck::noteAnswer(int answer)
{
    Must(!candidates.empty()); // the candidate we were checking must be there
    debugs(93,5, HERE << topCandidate() << " answer=" << answer);

    if (answer) { // the rule matched
        ServiceGroupPointer g = topGroup();
        if (g != NULL) { // the corresponding group found
            callBack(g);
            Must(done());
            return;
        }
    }

    // no match or the group disappeared during reconfiguration
    candidates.shift();
    checkCandidates();
}

/// call back with a possibly nil group; the job ends here because all failures
/// at this point are fatal to the access check process
void
Adaptation::AccessCheck::callBack(const ServiceGroupPointer &g)
{
    debugs(93,3, HERE << g);

    void *validated_cbdata;
    if (cbdataReferenceValidDone(callback_data, &validated_cbdata)) {
        callback(g, validated_cbdata);
    }
    mustStop("done"); // called back or will never be able to call back
}

Adaptation::ServiceGroupPointer
Adaptation::AccessCheck::topGroup() const
{
    ServiceGroupPointer g;
    if (candidates.size()) {
        if (AccessRule *r = FindRule(topCandidate())) {
            g = FindGroup(r->groupId);
            debugs(93,5, HERE << "top group for " << r->id << " is " << g);
        } else {
            debugs(93,5, HERE << "no rule for " << topCandidate());
        }
    } else {
        debugs(93,5, HERE << "no candidates"); // should not happen
    }

    return g;
}

/** Returns true iff the rule's service group will be used after ACL matches.
    Used to detect rules worth ACl-checking. */
bool
Adaptation::AccessCheck::isCandidate(AccessRule &r)
{
    debugs(93,7,HERE << "checking candidacy of " << r.id << ", group " <<
        r.groupId);

    ServiceGroupPointer g = FindGroup(r.groupId);

    if (!g) {
        debugs(93,7,HERE << "lost " << r.groupId << " group in rule" << r.id);
        return false;
    }

    const bool wants = g->wants(filter);
    debugs(93,7,HERE << r.groupId << (wants ? " wants" : " ignores"));
    return wants;
}
