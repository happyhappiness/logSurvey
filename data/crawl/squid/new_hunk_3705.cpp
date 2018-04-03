    }
    // TODO: Should we check receivedBodyTooLarge on the server-side as well?

    if (!group) {
        debugs(11,3, HERE << "no adapation needed");
        setFinalReply(virginReply());
        processReplyBody();
        return;
    }

    startAdaptation(group, originalRequest());
    processReplyBody();
}

void
ServerStateData::adaptationAclCheckDoneWrapper(Adaptation::ServiceGroupPointer group, void *data)
{
    ServerStateData *state = (ServerStateData *)data;
    state->adaptationAclCheckDone(group);
}
#endif

