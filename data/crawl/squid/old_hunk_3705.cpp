    }
    // TODO: Should we check receivedBodyTooLarge on the server-side as well?

    startedAdaptation = startAdaptation(service, originalRequest());

    if (!startedAdaptation && (!service || service->cfg().bypass)) {
        // handle ICAP start failure when no service was selected
        // or where the selected service was optional
        setFinalReply(virginReply());
        processReplyBody();
        return;
    }

    if (!startedAdaptation) {
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

void
ServerStateData::adaptationAclCheckDoneWrapper(Adaptation::ServicePointer service, void *data)
{
    ServerStateData *state = (ServerStateData *)data;
    state->adaptationAclCheckDone(service);
}
#endif

