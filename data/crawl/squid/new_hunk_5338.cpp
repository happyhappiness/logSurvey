    }
}

bool
ACL::requiresReply() const
{
    return false;
}

bool
ACL::requiresRequest() const
{
    return false;
}

int
ACL::checklistMatches(ACLChecklist *checklist)
{
    if (NULL == checklist->request && requiresRequest()) {
        debug(28, 1) ("WARNING: '%s' ACL is used but there is no"
                      " HTTP request -- not matching.\n", name);
        return 0;
    }

    if (NULL == checklist->reply && requiresReply()) {
        debug(28, 1) ("WARNING: '%s' ACL is used but there is no"
                      " HTTP reply -- not matching.\n", name);
        return 0;
    }

    debug(28, 3) ("aclMatchAcl: checking '%s'\n", cfgline);
    return match(checklist);
}

bool
ACLList::matches (ACLChecklist *checklist) const
{
    assert (_acl);
    AclMatchedName = _acl->name;
    debug(28, 3) ("ACLList::matches: checking %s%s\n",
                  op ? null_string : "!", _acl->name);

    if (_acl->checklistMatches(checklist) != op) {
        return false;
    }

    return true;
}

/* Warning: do not cbdata lock checklist here - it
 * may be static or on the stack
 */
int
aclCheckFast(const acl_access * A, ACLChecklist * checklist)
{
    allow_t allow = ACCESS_DENIED;
    PROF_start(aclCheckFast);
    debug(28, 5) ("aclCheckFast: list: %p\n", A);

    while (A) {
        allow = A->allow;
        checklist->matchAclList(A->aclList, true);

        if (checklist->finished()) {
            PROF_stop(aclCheckFast);
            return allow == ACCESS_ALLOWED;
        }

        A = A->next;
    }
