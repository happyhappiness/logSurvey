    if (abortOnBadEntry("entry went bad while waiting for ICAP ACL check"))
        return;

    startedIcap = startIcap(service, originalRequest());

    if (!startedIcap && (!service || service->bypass)) {
