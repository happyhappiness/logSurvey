}

void
ServerStateData::adaptationAclCheckDone(Adaptation::ServicePointer service)
{
    adaptationAccessCheckPending = false;

    if (abortOnBadEntry("entry went bad while waiting for ICAP ACL check"))
        return;
