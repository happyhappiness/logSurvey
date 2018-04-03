    PROF_start(aclCheckFast);

    preCheck("fast rules");
    asyncCaller_ = false;

    debugs(28, 5, "aclCheckFast: list: " << accessList);
    const Acl::Tree *acl = cbdataReference(accessList);
    if (acl != NULL && cbdataReferenceValid(acl)) {
        matchAndFinish(); // calls markFinished() on success

        // if finished (on a match or in exceptional cases), stop
        if (finished()) {
