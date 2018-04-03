ACLChecklist::fastCheck()
{
    PROF_start(aclCheckFast);
    currentAnswer(ACCESS_DUNNO);

    debugs(28, 5, "aclCheckFast: list: " << accessList);
    const acl_access *acl = cbdataReference(accessList);
    while (acl != NULL && cbdataReferenceValid(acl)) {
        matchAclList(acl->aclList, true);
        if (finished()) {
            currentAnswer(acl->allow);
            PROF_stop(aclCheckFast);
            cbdataReferenceDone(acl);
            return currentAnswer();
        }

        /*
         * Reference the next access entry
         */
        const acl_access *A = acl;
        acl = cbdataReference(acl->next);
        cbdataReferenceDone(A);
    }

    debugs(28, 5, "aclCheckFast: no matches, returning: " << currentAnswer());
    PROF_stop(aclCheckFast);

    return currentAnswer();
}


bool
ACLChecklist::checking() const
