}

void
ServerStateData::icapAclCheckDone(ICAPServiceRep::Pointer service)
{
    icapAccessCheckPending = false;

    if (abortOnBadEntry("entry went bad while waiting for ICAP ACL check"))
        return;
