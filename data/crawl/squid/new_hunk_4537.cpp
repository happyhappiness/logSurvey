    abortTransaction("ICAP failure");
}

HttpRequest *
ServerStateData::originalRequest()
{
    return request;
}

void
ServerStateData::icapAclCheckDone(ICAPServiceRep::Pointer service)
{
    icapAccessCheckPending = false;

    if (abortOnBadEntry("entry went bad while waiting for ICAP ACL check"))
        return;

    const bool startedIcap = startIcap(service, originalRequest());

    if (!startedIcap && (!service || service->bypass)) {
        // handle ICAP start failure when no service was selected
        // or where the selected service was optional
        entry->replaceHttpReply(reply);

        haveParsedReplyHeaders();
        processReplyBody();

        return;
    }

    if (!startedIcap) {
        // handle start failure for an essential ICAP service
        ErrorState *err = errorCon(ERR_ICAP_FAILURE,
            HTTP_INTERNAL_SERVER_ERROR, originalRequest());
        err->xerrno = errno;
        errorAppendEntry(entry, err);
        abortTransaction("ICAP start failure");
        return;
    }

    processReplyBody();
}

#endif
